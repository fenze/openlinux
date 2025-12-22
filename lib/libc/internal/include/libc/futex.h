#ifndef __LIBC_FUTEX_H
#define __LIBC_FUTEX_H

int __futex_wait(volatile int *, int);
int __futex_wake(volatile int *, int);

#endif
