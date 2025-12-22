#ifndef __LIBC_THREAD_H
#define __LIBC_THREAD_H

#include <stdatomic.h>
#include <stddef.h>
#include <stdint.h>

#define THREAD_STACK_SIZE (1024 * 1024)
#define THREAD_GUARD_SIZE 8192

enum __thread_state { THREAD_STATE_EXITED, THREAD_STATE_JOINABLE, THREAD_STATE_DETACHED };

struct tls {
	void *data;
	size_t length;
	size_t size;
	size_t align;
};

struct __thread_self {
	struct __thread_self *self;

	/* Backing mapping for this thread (used by thrd_join/thrd_detach to munmap safely) */
	void *map_base;
	size_t map_size;

#ifdef __aarch64__
	uintptr_t *dtv;
	uintptr_t canary;
#endif

	long tid;
	int res;
	int errno_v;
	volatile int state;

#ifdef __x86_64__
	uintptr_t canary;
	uintptr_t *dtv;
#endif
};

void __libc_tls_copy(void *);

#if defined(__x86_64__)
long __clone(long (*fn)(void *), void *arg, unsigned long flags, void *child_stack, long *ptid, void *newtls,
	     long *ctid);
#endif

#endif
