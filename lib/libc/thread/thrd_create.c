#include <__thread.h>
#include <asm/prctl.h>
#include <errno.h>
#include <libc.h>
#include <linux/sched.h>
#include <sched.h>
#include <signal.h>
#include <stdio.h>
#include <sys/mman.h>
#include <syscall.h>
#include <threads.h>
#include <unistd.h>

struct thread_start {
	struct __thread_self *self;
	thrd_start_t func;
	void *arg;
};

static long __thread_start(void *arg)
{
	struct thread_start *ts = (struct thread_start *)arg;
	syscall(set_tid_address, &ts->self->tid);
	int r = ts->func(ts->arg);
	thrd_exit(r);
	__builtin_unreachable();
}

int thrd_create(thrd_t *thr, thrd_start_t func, void *arg)
{
	struct thread_start *ts;

	if ((void *)thr == NULL || func == NULL)
		return thrd_error;

	/* Ensure callers never observe an uninitialized thread handle on failure. */
	*thr = NULL;

	void *map;
	size_t size = THREAD_GUARD_SIZE + THREAD_STACK_SIZE + __libc.tls.size + sizeof(struct __thread_self);
	map = mmap(NULL, size, PROT_NONE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (__predict_false(map == MAP_FAILED))
		return thrd_nomem;

	if (__predict_false(mprotect((unsigned char *)map + THREAD_GUARD_SIZE, size - THREAD_GUARD_SIZE,
				     PROT_READ | PROT_WRITE) < 0)) {
		munmap(map, size);
		return thrd_error;
	}

	unsigned char *base = (unsigned char *)map;

	/* Place TCB at the very end of the mapping. */
	struct __thread_self *tcb = (struct __thread_self *)(base + size - sizeof(struct __thread_self));

	/* Place TLS immediately below the TCB, aligned down. */
	unsigned char *tls_end = (unsigned char *)tcb;

	size_t tls_align = __libc.tls.align;
	if (tls_align == 0 || (tls_align & (tls_align - 1)) != 0)
		tls_align = sizeof(void *);
	if (tls_align < sizeof(void *))
		tls_align = sizeof(void *);

	unsigned char *tls_start =
		(unsigned char *)(((uintptr_t)(tls_end - __libc.tls.size)) & ~((uintptr_t)tls_align - 1));

	__libc_tls_copy(tls_start);

	/* Build initial stack just below TLS. */
	unsigned char *stack_top = tls_start;
	ts = (struct thread_start *)(stack_top - sizeof(struct thread_start));
	stack_top -= sizeof(struct thread_start);

	ts->self = tcb;
	ts->func = func;
	ts->arg = arg;

	stack_top = (unsigned char *)((uintptr_t)stack_top & ~15UL);

	tcb->self = tcb;
	tcb->map_base = map;
	tcb->map_size = size;
	tcb->errno_v = 0;
	tcb->dtv = 0;
	tcb->state = THREAD_STATE_JOINABLE;

	unsigned long flags = CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_THREAD | CLONE_SYSVSEM |
			      CLONE_SETTLS | CLONE_PARENT_SETTID | CLONE_CHILD_SETTID | CLONE_CHILD_CLEARTID;

#if defined(__x86_64__)
	long tid = __clone(__thread_start, ts, flags, stack_top, &tcb->tid, tcb, &tcb->tid);
#endif

	if (__predict_false(tid < 0)) {
		munmap(map, size);
		return thrd_error;
	}

#if !defined(__x86_64__)
	if (tid == 0) {
		__thread_start(ts);
		__builtin_unreachable();
	}
#endif

	tcb->tid = tid;

	*thr = tcb;

	return thrd_success;
}
