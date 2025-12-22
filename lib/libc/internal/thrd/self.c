#include <libc/tcb.h>

__attribute__((__always_inline__)) void *__libc_thread_self(void)
{
	return __libc_tcb_get();
}
