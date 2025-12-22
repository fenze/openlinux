#ifndef __LIBC_LIBC_H
#define __LIBC_LIBC_H

#include <__stdio.h>
#include <stdatomic.h>
#include <stddef.h>
#include <sys/cdefs.h>

#define weak_reference(old, new) extern __typeof(old)((new)) __attribute__((__weak__, __alias__(#old)))

struct libc {
	size_t *auxv;

	struct {
		void *base;
		size_t size;
		size_t align;
	} tls;

	enum {
		LIBC_ENVP_TOUCHED = 1 << 0,
	} flags;

	struct {
		volatile atomic_flag abort;
		volatile atomic_flag malloc;
		volatile atomic_flag environ;
	} lock;

	struct __FILE stdin;
	struct __FILE stdout;
	struct __FILE stderr;
};

extern struct libc __libc;

#define panic(__errmsg) __libc_panic(__FILE__ ":" __STRING(__LINE__) ": ", __PRETTY_FUNCTION__, ": " __STRING(__errmsg))

#define panic_if(__cond, __errmsg)           \
	do {                                 \
		if (__predict_false(__cond)) \
			panic(__errmsg);     \
	} while (0)

__dead void __libc_panic(const char *, const char *, const char *);
#endif
