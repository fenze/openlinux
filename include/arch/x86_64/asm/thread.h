#ifndef __ASM_THREAD_H
#define __ASM_THREAD_H

#include <stdint.h>

static __inline uintptr_t __thread_self(void)
{
	uintptr_t tp;
	__asm__("mov %%fs:0,%0" : "=r"(tp));
	return tp;
}

#endif
