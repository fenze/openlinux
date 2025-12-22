-include Kbuild

# Disable builti-n rules and variables
MAKEFLAGS += -r -R

# Disable output of entering/leaving directory messages
MAKEFLAGS += --no-print-directory

export MSG = @printf '\033[34m%-8s\033[0m %s\n'

this-makefile = $(lastword $(MAKEFILE_LIST))
srctree = $(realpath $(dir $(this-makefile)))
.DEFAULT_GOAL := all

LLVM ?= 1
ifneq ($(LLVM),1)
  ifneq ($(filter %/,$(LLVM)),)
    LLVM_PREFIX = $(LLVM)
  else ifneq ($(filter -%,$(LLVM)),)
    LLVM_SUFFIX = $(LLVM)
  endif
endif

# Variables
ifeq ($(LLVM),1)
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

# CFLAGS

KBUILD_CFLAGS := -x c

KBUILD_CFLAGS += -Wall -Wextra
KBUILD_CFLAGS += -nostdinc
KBUILD_CFLAGS += -target $(ARCH)-linux-eabi
KBUILD_CFLAGS += -ffreestanding
KBUILD_CFLAGS += -I$(srctree)/include
KBUILD_CFLAGS += -I$(srctree)/include/arch/$(ARCH)

KBUILD_CFLAGS += -std=c11
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
KBUILD_CFLAGS += -g -O0 -fno-omit-frame-pointer -fno-stack-protector
else
KBUILD_CFLAGS += -O2 -fdata-sections -ffunction-sections
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

PHONY :=

export Q srctree MAKEFLAGS KCONFIG_CONFIG \
       KBUILD_CFLAGS KBUILD_ASFLAGS KBUILD_LDFLAGS

PHONY += install
all: compile_commands.json
	$(Q)$(MAKE) -f scripts/makefile.build obj=$(obj)

PHONY += install
install: all
	$(Q)$(MAKE) -f scripts/makefile.build obj=$(obj) install
	mkdir -p $(O)/usr
	cp -r $(srctree)/include $(O)/usr/
	rm -rf $(O)/usr/include/arch $(O)/usr/include/generated ${O}/usr/include/config

PHONY += clean
clean:
	$(Q)$(MAKE) -f scripts/makefile.build obj=$(obj) clean
	$(Q)rm -f $(srctree)/include/config/auto.conf
	$(Q)rm -f $(srctree)/include/generated/autoconf.h
	$(Q)rm -rf $(srctree)/dist

PHONY += distclean
distclean: clean
	$(Q)$(MAKE) -C scripts/kconfig clean
	$(Q)rm -f compile_commands.json

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
	@echo "  install              - Install the built files"
	@echo "  clean                - Clean build files"
	@echo "  distclean            - Clean all generated files"
	@echo "  menuconfig           - Launch the menu-based configuration tool"
	@echo "  include-what-you-use - Run include-what-you-use on the source files"
	@echo "  clang-tidy           - Run clang-tidy on the source files"
	@echo "  clang-format         - Format source files using clang-format"

compile_commands.json:
	$(Q)bear -- $(MAKE) -f scripts/makefile.build obj=$(obj) all

PHONY += menuconfig
menuconfig:
	$(Q)$(MAKE) -C $(srctree)/scripts/kconfig menuconfig

PHONY += include-what-you-use
include-what-you-use: compile_commands.json
	$(Q)iwyu_tool.py -p. -j4 -- -Xiwyu --update_comments -Xiwyu --transitive_includes_only -Xiwyu --no_internal_mappings | \
		fix_includes.py --comments \
			--quoted_includes_first \
			--nosafe_headers \
			--update_comments \
			--reorder

PHONY += clang-tidy
clang-tidy: compile_commands.json
	$(Q)clang-tidy -header-filter=.* -p=. -fix -fix-errors $(shell find . -name '*.c' -o -name '*.h' | grep -v './scripts/\|dtoa\|linux\|arch\|bits\|libm') \
		--export-fixes=clang-tidy-fixes.yaml

PHONY += clang-format
clang-format:
	$(Q)clang-format -i $(shell find . -name '*.c' -o -name '*.h' | grep -v './scripts/')

%/include/config/auto.conf %/include/generated/autoconf.h: $(KCONFIG_CONFIG) compile_commands.json
	$(Q)$(MAKE) -f scripts/kconfig/makefile syncconfig

.PHONY: $(PHONY)
