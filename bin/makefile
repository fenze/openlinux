include ../config

BINS := $(wildcard $(CURDIR)/*/)

all:
	for bin in $(BINS); do \
		$(MAKE) -C $$bin; \
	done

install:
	for bin in $(BINS); do \
		$(MAKE) -C $$bin install; \
	done

clean:
	for bin in $(BINS); do \
		$(MAKE) -C $$bin clean; \
	done

.PHONY: all install clean
