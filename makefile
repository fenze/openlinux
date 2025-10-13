include config

all: | build
	for lib in $(LIBS); do \
		$(MAKE) -C lib/$$lib install; \
	done
	$(MAKE) -C bin install

build/$(ARCH)/sysroot/usr/include:
	mkdir -p $@

build: build/$(ARCH)/sysroot/usr/include
	mkdir -p $@/$(ARCH)/sysroot/lib
	mkdir -p $@/$(ARCH)/sysroot/bin
	rsync -aq --no-perms include/ $@/$(ARCH)/sysroot/usr/include

clean:
	for lib in $(LIBS); do \
		$(MAKE) -C lib/$$lib clean; \
	done
	$(MAKE) -C bin clean
	rm -rf build

docker:
	docker buildx build --platform=linux/amd64 -t openlinux:latest --load .
	docker run --rm -it openlinux:latest /bin/sh

.PHONY: all build clean
