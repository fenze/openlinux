#ifndef __ASM_VDSO_H
#define __ASM_VDSO_H

/*
 * vDSO support interface.
 *
 * IMPORTANT:
 * Do not define storage in this header. This header is included by multiple
 * translation units; defining `static` variables here causes each TU to get its
 * own copy, which makes initialization inconsistent and prevents dead-stripping.
 *
 * The actual storage/definitions must live in a single .c file (e.g.
 * `lib/libc/internal/init/vdso.c`), and this header should only declare them.
 */

struct timespec;

#define __VDSO_CLOCK_GETTIME
#define __VDSO_GETCPU
#define __VDSO_TIME

/* Resolved vDSO entry points (set by __init_vdso). */
extern int (*__vdso_clock_gettime)(int, struct timespec *);
extern int (*__vdso_getcpu)(unsigned *, unsigned *, void *);
extern int (*__vdso_time)(long *);

/* Symbol table used by __init_vdso to locate vDSO functions. */
struct __vdso_sym {
	const char *name;
	void *func;
};

extern struct __vdso_sym __vdso_symtab[];

#endif
