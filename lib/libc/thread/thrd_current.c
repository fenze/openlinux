#include <libc/thread.h>
#include <threads.h>

thrd_t thrd_current(void)
{
	return __libc_thread_self();
}
