#ifndef __LIBC_LIBC_H
#define __LIBC_LIBC_H

#include <stdatomic.h>
#include <features.h>

#include <__stdio.h>
#include <thread.h>

#define __IMPL(_v) ((__##typeof(_v))_v)

#define likely(x)     __builtin_expect(!!(x), 1)
#define unlikely(x)   __builtin_expect(!!(x), 0)
#define __unused      __attribute__((unused))
#define aligned(type) __attribute__((aligned(__alignof__(type))))
#define weak_reference(old, new) \
	extern __typeof(old) new __attribute__((__weak__, __alias__(#old)))

static struct {
	enum {
		LIBC_ENVP_TOUCHED = 1 << 0,
	} flags;
	struct {
		volatile atomic_flag abort;
		volatile atomic_flag malloc;
		volatile atomic_flag environ;
	} lock;
} libc = { .lock = { ATOMIC_FLAG_INIT, ATOMIC_FLAG_INIT, ATOMIC_FLAG_INIT } };

#endif
