#ifndef __ASM_VDSO_H
#define __ASM_VDSO_H

struct timespec;

extern int (*__vdso_clock_gettime)(int, struct timespec *);
extern int (*__vdso_getcpu)(unsigned *, unsigned *, void *);
extern int (*__vdso_time)(long *);

#endif
