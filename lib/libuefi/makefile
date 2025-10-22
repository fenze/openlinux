include ../../config

CFLAGS :=
CFLAGS += -fshort-wchar -fno-strict-aliasing -ffreestanding -fno-stack-protector 
CFLAGS += -fno-stack-check -I. -nostdlib -Bsymbolic
CFLAGS += -target x86_64-pc-win32-coff

ifeq ($(ARCH),x86_64)
  CFLAGS += -mno-red-zone
endif

libuefi.a: uefi.o
	$(TASK) AR $@
	$(HOSTAR) rcs --format=coff $@ $^

uefi.o: uefi.c uefi.h
	$(TASK) CC $(notdir $@)
	$(HOSTCC) -MMD -MP $(CFLAGS) -c uefi.c -o $@

$(CURDIR)/../../build/$(ARCH)/sysroot/usr/include/uefi.h: uefi.h
	$(TASK) INSTALL include/$^
	cp -f $^ $@

$(CURDIR)/../../build/$(ARCH)/sysroot/lib/libuefi.a: libuefi.a
	$(TASK) INSTALL lib/$^
	cp -f $^ $@

install: $(CURDIR)/../../build/$(ARCH)/sysroot/lib/libuefi.a \
	$(CURDIR)/../../build/$(ARCH)/sysroot/usr/include/uefi.h


clean:
	rm -f uefi.o uefi.d libuefi.a

.PHONY: clean
