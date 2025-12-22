#ifndef __LIBC_ATOMIC_H
#define __LIBC_ATOMIC_H

#include <libc/futex.h>
#include <sched.h>
#include <stdatomic.h>
#include <unistd.h>

#define LIBC_LOCK(__lock)   __libc_lock(&((__lock)))
#define LIBC_UNLOCK(__lock) __libc_unlock(&((__lock)))

__attribute__((__always_inline__)) __inline void __libc_unlock(volatile atomic_flag *lock)
{
	atomic_flag_clear_explicit(lock, memory_order_release);
	__futex_wake((volatile int *)lock, 1);
}

__attribute__((__always_inline__)) __inline void __libc_lock(volatile atomic_flag *lock)
{
	if (atomic_flag_test_and_set_explicit(lock, memory_order_acquire) == 0)
		return;

	while (1) {
		__futex_wait((volatile int *)lock, 1);

		if (atomic_flag_test_and_set_explicit(lock, memory_order_acquire) == 0)
			return;

		sched_yield();
	}
}

#endif
