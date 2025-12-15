#ifndef __ASM_VDSO_H
#define __ASM_VDSO_H

struct timespec;

#define __VDSO_CLOCK_GETTIME
#define __VDSO_GETCPU
#define __VDSO_TIME

static int (*__vdso_clock_gettime)(int, struct timespec *) = 0;
static int (*__vdso_getcpu)(unsigned *, unsigned *, void *) = 0;
static int (*__vdso_time)(long *) = 0;

struct {
	const char *name;
	void *func;
} __vdso_symtab[] = { { "__vdso_clock_gettime", (void *)&__vdso_clock_gettime },
		      { "__vdso_getcpu", (void *)&__vdso_getcpu },
		      { "__vdso_time", (void *)&__vdso_time },
		      { 0, 0 } };

#endif
