#include <__thread.h>
#include <libc/futex.h>
#include <stdatomic.h>
#include <sys/mman.h>
#include <threads.h>
#include <unistd.h>

int thrd_detach(thrd_t thr)
{
	struct __thread_self *tcb = (struct __thread_self *)thr;

	if (tcb == NULL)
		return thrd_error;

	int state = atomic_exchange_explicit(&tcb->state, THREAD_STATE_DETACHED, memory_order_seq_cst);

	if (state == THREAD_STATE_EXITED) {
		if (tcb->map_base && tcb->map_size)
			munmap(tcb->map_base, tcb->map_size);
	}

	return thrd_success;
}
