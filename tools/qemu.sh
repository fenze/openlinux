#!/bin/sh

task() {
	printf '  \033[34m%+8s\033[m %s\n' "$1" "$2"
}

if [ ! -f "build/x86_64/kernel" ]; then
	task "ERROR" "Kernel not found! Please build the kernel first."
	exit 1
fi

task "INFO" "Starting QEMU..."

ARCH="$1"
OSIMAGE="$2"

if [ ! -f "$OSIMAGE" ]; then
	task "ERROR" "System image not found! Please build the image first."
	exit 1
fi

BZIMAGE="build/x86_64/kernel"

qemu-system-x86_64 \
	-drive if=pflash,format=raw,readonly,file=/opt/homebrew/share/qemu/edk2-x86_64-code.fd \
	-drive if=pflash,format=raw,file=/opt/homebrew/share/qemu/edk2-i386-vars.fd \
	-drive format=raw,file="$OSIMAGE",id=maindisk,if=none \
	-device ahci,id=ahci \
	-device ide-hd,drive=maindisk,bus=ahci.0 \
	-boot order=c \
	-boot menu=on \
	-cpu max \
	--nographic

if false; then
	qemu-system-"$ARCH" \
		-cpu max \
		-kernel "$BZIMAGE" \
		-drive file="$OSIMAGE",format=raw,if=none,id=mydrive \
		-device virtio-blk-pci,drive=mydrive \
		-append "root=/dev/vda1 rw rootwait earlyprintk=serial loglevel=8 ignore_loglevel console=ttyS0 init=/bin/init" \
		--nographic
fi
