#include <thread.h>
#include <asm-generic/signal.h>
#include <syscall.h>

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
