-include Kbuild

# Disable builti-n rules and variables
MAKEFLAGS += -r -R

# Disable output of entering/leaving directory messages
MAKEFLAGS += --no-print-directory

export MSG = @printf '\033[34m%-8s\033[0m %s\n'

this-makefile = $(lastword $(MAKEFILE_LIST))
srctree = $(realpath $(dir $(this-makefile)))
.DEFAULT_GOAL := all

ifndef ARCH
  ARCH := x86_64
endif

ifeq ($(CCACHE),1)
  CC      := ccache $(CC)
endif

ifndef O
  O := $(srctree)/dist
else
  O := $(srctree)/$(O)
endif

export CC LD AR STRIP CROSS_COMPILE ARCH O

ifeq ($(V),1)
  Q :=
else
  Q := @
  MAKEFLAGS += -s
endif

ifdef M
  obj = $(M)/
endif

KCONFIG_CONFIG ?= .config

-include ${KCONFIG_CONFIG}

ifneq ($(CONFIG_LLVM),y)
  ifneq ($(filter %/,$(LLVM)),)
    LLVM_PREFIX = $(LLVM)
  else ifneq ($(filter -%,$(LLVM)),)
    LLVM_SUFFIX = $(LLVM)
  endif
endif

ifeq ($(CONFIG_LLVM),y)
  CC      = $(LLVM_PREFIX)clang$(LLVM_SUFFIX)
  LD      = $(LLVM_PREFIX)ld.lld$(LLVM_SUFFIX)
  AR      = $(LLVM_PREFIX)llvm-ar$(LLVM_SUFFIX)
  STRIP   = $(LLVM_PREFIX)llvm-strip$(LLVM_SUFFIX)
else
  CC = $(CROSS_COMPILE)gcc
  LD = $(CROSS_COMPILE)ld
  AR = $(CROSS_COMPILE)ar
  STRIP = $(CROSS_COMPILE)strip
endif

KBUILD_CFLAGS := -x c

KBUILD_CFLAGS += -Wall -Wextra
KBUILD_CFLAGS += -nostdinc
KBUILD_CFLAGS += -target $(ARCH)-linux-eabi
KBUILD_CFLAGS += -ffreestanding
KBUILD_CFLAGS += -I$(srctree)/include
KBUILD_CFLAGS += -I$(srctree)/include/arch/$(ARCH)

KBUILD_CFLAGS += -std=c23
KBUILD_CFLAGS += -fno-common
KBUILD_CFLAGS += -fno-PIE
KBUILD_CFLAGS += -fstrict-aliasing

KBUILD_CFLAGS += -fno-delete-null-pointer-checks

# Disable overflow optimizations
KBUILD_CFLAGS += -fno-strict-overflow

# Disable stack check
KBUILD_CFLAGS += -fno-stack-check

# Weird loops transformations to wcslen
KBUILD_CFLAGS += -fno-builtin-wcslen

ifeq ($(CONFIG_WERROR),y)
KBUILD_CFLAGS += -Werror
endif

KBUILD_LDFLAGS :=
KBUILD_ASFLAGS :=
ifeq ($(CONFIG_DEBUG),y)
KBUILD_CFLAGS += -g
else
KBUILD_CFLAGS += -fdata-sections -ffunction-sections
KBUILD_CFLAGS += -fno-unwind-tables -fomit-frame-pointer
KBUILD_CFLAGS += -flto

KBUILD_LDFLAGS += --gc-sections
KBUILD_LDFLAGS += --build-id=none
KBUILD_LDFLAGS += --as-needed
# KBUILD_LDFLAGS += --strip-all
KBUILD_LDFLAGS += -z relro -z now -z noexecstack
KBUILD_LDFLAGS += --no-undefined
KBUILD_LDFLAGS += --icf=all

KBUILD_ASFLAGS +=
endif

# Assembly does not need -nostdinc; clang warns it is unused.
KBUILD_ASFLAGS += -target $(ARCH)-linux-eabi
KBUILD_ASFLAGS += -I$(srctree)/include
KUILD_ASFLAGS += -I$(srctree)/include/arch/$(ARCH)

ifdef CONFIG_OPTIMIZATION_LEVEL_O0
KBUILD_CFLAGS += -O0
else ifdef CONFIG_OPTIMIZATION_LEVEL_G
KBUILD_CFLAGS += -Og
else ifdef CONFIG_OPTIMIZATION_LEVEL_O1
KBUILD_CFLAGS += -O1
else ifdef CONFIG_OPTIMIZATION_LEVEL_O2
KBUILD_CFLAGS += -O2
else ifdef CONFIG_OPTIMIZATION_LEVEL_O3
KBUILD_CFLAGS += -O3
else ifdef CONFIG_OPTIMIZATION_LEVEL_Os
KBUILD_CFLAGS += -Os
else ifdef CONFIG_OPTIMIZATION_LEVEL_Oz
KBUILD_CFLAGS += -Oz
else ifdef CONFIG_OPTIMIZATION_LEVEL_FAST
KBUILD_CFLAGS += -Ofast
endif

PHONY :=

export Q srctree MAKEFLAGS KCONFIG_CONFIG \
       KBUILD_CFLAGS KBUILD_ASFLAGS KBUILD_LDFLAGS

PHONY += install
all:
	$(Q)$(MAKE) -f scripts/makefile.build obj=$(obj)

PHONY += install
install: all
	$(Q)$(MAKE) -f scripts/makefile.build obj=$(obj) install
ifdef CONFIG_LIB_LIBC_HEADERS
	mkdir -p $(O)/usr
	cp -r $(srctree)/include $(O)/usr/
	rm -rf $(O)/usr/include/arch $(O)/usr/include/generated ${O}/usr/include/config
endif

PHONY += clean
clean:
	$(Q)$(MAKE) -f scripts/makefile.build obj=$(obj) clean
	$(Q)rm -f $(srctree)/include/config/auto.conf
	$(Q)rm -f $(srctree)/include/generated/autoconf.h
	$(Q)rm -rf $(srctree)/dist

PHONY += distclean
distclean: clean
	$(Q)$(MAKE) -C scripts/kconfig clean

$(KCONFIG_CONFIG):
	@echo >&2 '***'
	@echo >&2 '*** Configuration file "$@" not found!'
	@echo >&2 '***'
	@echo >&2 '*** Please run some configurator'
	@echo >&2 '*** (e.g. "make oldconfig" or "make menuconfig"'
	@echo >&2 '***'
	@false

PHONY += help
help:
	@echo "Available make targets:"
	@echo "  all                  - Build the project (default)"
	@echo "  clang-format         - Format source files using clang-format"
	@echo "  clean                - Clean build files"
	@echo "  distclean            - Clean all generated files"
	@echo "  install              - Install the built files"
	@echo "  menuconfig           - Launch the menu-based configuration tool"
	@echo "Flags:"
	@echo "  o=<dir>/             - Destination directory"
	@echo "  obj=<dir>/           - Build single target"

PHONY += menuconfig
menuconfig:
	$(Q)$(MAKE) -C $(srctree)/scripts/kconfig menuconfig

PHONY += clang-format
clang-format:
	$(Q)clang-format -i $(shell find . -name '*.c' -o -name '*.h' | grep -v './scripts/')

%/include/config/auto.conf %/include/generated/autoconf.h: $(KCONFIG_CONFIG)
	$(Q)$(MAKE) -f scripts/kconfig/makefile syncconfig

.PHONY: $(PHONY)
