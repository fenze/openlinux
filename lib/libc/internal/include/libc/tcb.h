#ifndef __LIBC_TCB_H
#define __LIBC_TCB_H

#include <stdint.h>

void *__libc_tcb_get(void);
void __libc_tcb_set(uint64_t);

#endif
