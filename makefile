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

export CC LD AR STRIP CROSS_COMPILE ARCH

ifeq ($(V),1)
  Q :=
else
  Q := @
  MAKEFLAGS += -s
endif

ifdef M
  obj = $(M)/
endif

# CFLAGS

KBUILD_CFLAGS :=

KBUILD_CFLAGS += -Wall -Wextra
KBUILD_CFLAGS += -nostdinc
KBUILD_CFLAGS += -target $(ARCH)-linux-eabi
KBUILD_CFLAGS += -I$(srctree)/include
KBUILD_CFLAGS += -I$(srctree)/include/arch/$(ARCH)

KBUILD_CFLAGS += -std=c11
KBUILD_CFLAGS += -fno-common
KBUILD_CFLAGS += -fno-PIE
KBUILD_CFLAGS += -fstrict-aliasing

KBUILD_CFLAGS += -fno-delete-null-pointer-checks
KBUILD_CFLAGS += -flto

# Disable overflow optimizations
KBUILD_CFLAGS += -fno-strict-overflow

# Disable stack check
KBUILD_CFLAGS += -fno-stack-check

# Weird loops transformations to wcslen
KBUILD_CFLAGS += -fno-builtin-wcslen

ifeq ($(CONFIG_WERROR),y)
KBUILD_CFLAGS += -Werror
endif

ifeq ($(CONFIG_DEBUG),y)
KBUILD_CFLAGS += -g -Og -fno-omit-frame-pointer
endif

KBUILD_ASFLAGS :=

# Assembly does not need -nostdinc; clang warns it is unused.
KBUILD_ASFLAGS += -target $(ARCH)-linux-eabi
KBUILD_ASFLAGS += -I$(srctree)/include
KBUILD_ASFLAGS += -I$(srctree)/include/arch/$(ARCH)

# LDFLAGS
KBUILD_LDFLAGS :=

KBUILD_LDFLAGS += --gc-sections
KBUILD_LDFLAGS += --build-id=none
KBUILD_LDFLAGS += --as-needed

PHONY :=

KCONFIG_CONFIG ?= .config

export Q srctree MAKEFLAGS KCONFIG_CONFIG \
       KBUILD_CFLAGS KBUILD_ASFLAGS KBUILD_LDFLAGS

all: $(srctree)/include/config/auto.conf $(srctree)/include/generated/autoconf.h
	$(Q)$(MAKE) -f scripts/makefile.build obj=$(obj)

clean:
	$(Q)$(MAKE) -f scripts/makefile.build obj=$(obj) clean
	$(Q)rm -f $(srctree)/include/config/auto.conf
	$(Q)rm -f $(srctree)/include/generated/autoconf.h

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

compile_commands.json:
	$(Q)bear -- $(MAKE) -f scripts/makefile.build obj=$(obj)

PHONY += menuconfig
menuconfig:
	$(Q)$(MAKE) -f scripts/kconfig/makefile menuconfig

PHONY += defconfig
defconfig:
	$(Q)$(MAKE) -f scripts/kconfig/makefile defconfig

include-what-you-use: compile_commands.json
	$(Q)iwyu_tool.py -p. -j$(nproc) -- -Xiwyu --update_comments -Xiwyu --transitive_includes_only -Xiwyu --no_internal_mappings | \
		fix_includes.py --comments \
			--quoted_includes_first \
			--nosafe_headers \
			--update_comments \
			--reorder

clang-tidy: compile_commands.json
	$(Q)run-clang-tidy.py \
		-p . \
		-fix \
		-fix-errors \
		-header-filter='.*' \
		-source-filter='.*\.(c|h)$$' \
		-exclude-header-filter='(scripts/|dtoa|linux|arch|bits)' \
		-j $(shell nproc)

clang-format:
	$(Q)clang-format -i $(shell find . -name '*.c' -o -name '*.h' | grep -v './scripts/')

%/include/config/auto.conf %/include/generated/autoconf.h: $(KCONFIG_CONFIG) compile_commands.json
	$(Q)$(MAKE) -f scripts/kconfig/makefile syncconfig

.PHONY: $(PHONY)
