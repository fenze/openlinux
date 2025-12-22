#include <__thread.h>
#include <libc/futex.h>
#include <stdatomic.h>
#include <sys/mman.h>
#include <threads.h>
#include <unistd.h>

_Noreturn void thrd_exit(int res)
{
	struct __thread_self *self = thrd_current();

	self->res = res;

	int state = atomic_load_explicit((int *)&self->state, memory_order_seq_cst);
	if (state == THREAD_STATE_DETACHED) {
		if (self->map_base && self->map_size)
			munmap(self->map_base, self->map_size);
		_exit(0);
	}

	atomic_store_explicit(&self->state, THREAD_STATE_EXITED, memory_order_seq_cst);
	__futex_wake(&self->state, 1);

	_exit(0);
}
