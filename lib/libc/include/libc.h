#ifndef __LIBC_LIBC_H
#define __LIBC_LIBC_H

#include <stdatomic.h>

#define weak_reference(old, new) \
	extern __typeof(old) new __attribute__((__weak__, __alias__(#old)))

static struct {
	struct {
		volatile atomic_flag malloc;
	} lock;
} libc = { .lock = { ATOMIC_FLAG_INIT } };

#endif
