#include "errno.h"	   // for EINVAL

#include <__thread.h>		// for __thread_self
#include <asm-generic/signal.h> // for _NSIG
#include <syscall.h>		// for __syscall_2, syscall

typedef struct __thread_self *pthread_t;

int pthread_kill(pthread_t thread, int sig)
{
	if (sig < 0 || sig > _NSIG) {
		return EINVAL;
	}

	if (thread->tid == 0) {
		return 0;
	}

	return syscall(tkill, thread->tid, sig);
}
