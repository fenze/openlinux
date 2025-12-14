FROM alpine:latest
RUN apk add --no-cache e2fsprogs util-linux cpio make xz e2fsprogs-extra sfdisk losetup kpartx jq dosfstools mtools
WORKDIR /openlinux
