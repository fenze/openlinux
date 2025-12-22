#include <libc/tcb.h>

__attribute__((__always_inline__)) void __libc_tcb_set(uint64_t tcb)
{
	__asm__ volatile("wrfsbase %0" ::"r"(tcb));
}

__attribute__((__always_inline__)) void *__libc_tcb_get(void)
{
	void *tcb;
	__asm__ volatile("rdfsbase %0" : "=r"(tcb));
	return tcb;
}
