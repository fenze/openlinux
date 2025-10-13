FROM scratch

COPY build/x86_64/sysroot /

# To run this image interactively, use:
# docker run -it --rm openlinux:latest /bin/sh
