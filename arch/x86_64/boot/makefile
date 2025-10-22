include ../../../config

LD := lld-link

CFLAGS :=
CFLAGS += -I../../../lib/libuefi
CFLAGS += -target x86_64-pc-win32-coff
CFLAGS += -fno-stack-protector -fshort-wchar

ifeq ($(ARCH),x86_64)
CFLAGS += -mno-red-zone
endif

LDFLAGS := -subsystem:efi_application -nodefaultlib -dll -entry:_start
LIBUEFI := ../../../lib/libuefi/libuefi.a

EFI_DIR := ../../../build/$(ARCH)/EFI

all: boot.efi

boot.efi: boot.o
	$(LD) $(LDFLAGS) -out:$@ boot.o $(LIBUEFI)

boot.o: boot.c
	$(CC) $(CFLAGS) -c boot.c

install: boot.efi
	mkdir -p $(EFI_DIR)/BOOT
	cp boot.efi $(EFI_DIR)/BOOT/BOOTX64.EFI

clean:
	rm -f boot.o boot.efi boot.lib

.PHONY: all install
