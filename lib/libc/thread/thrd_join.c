#include "stddef.h"
#include <__thread.h>
#include <libc/futex.h>
#include <stdatomic.h>
#include <sys/mman.h>
#include <threads.h>

int thrd_join(thrd_t thr, int *res)
{
	struct __thread_self *tcb = (struct __thread_self *)thr;
	if (tcb == NULL)
		return thrd_error;

	int state = atomic_load_explicit(&tcb->state, memory_order_seq_cst);
	if (state == THREAD_STATE_DETACHED)
		return thrd_error; // Cannot join a detached thread

	while (atomic_load_explicit(&tcb->state, memory_order_seq_cst) != THREAD_STATE_EXITED) {
		int cur = atomic_load_explicit(&tcb->state, memory_order_seq_cst);
		int r = __futex_wait((volatile int *)&tcb->state, cur);
		if (r < 0)
			return thrd_error;
	}

	if (res) {
		*res = tcb->res;
	}

	atomic_store_explicit(&tcb->state, THREAD_STATE_JOINABLE, memory_order_seq_cst);
	__futex_wake((volatile int *)&tcb->state, 1);

	if (tcb->map_base == NULL || tcb->map_size == 0)
		return thrd_error;

	munmap(tcb->map_base, tcb->map_size);

	return thrd_success;
}
