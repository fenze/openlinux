#ifndef __LIBC_LIBC_H
#define __LIBC_LIBC_H

#include <stddef.h>
#include <stdatomic.h>

#define weak_reference(old, new) extern __typeof(old)((new)) __attribute__((__weak__, __alias__(#old)))

struct libc {
	size_t auxv[32];

	enum {
		LIBC_ENVP_TOUCHED = 1 << 0,
	} flags;

	struct {
		volatile atomic_flag abort;
		volatile atomic_flag malloc;
		volatile atomic_flag environ;
	} lock;
};

extern struct libc __libc;

#endif
