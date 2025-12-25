#define __ASSEMBLY__
#include <asm-generic/signal.h>
#undef __ASSEMBLY__

#include <errno.h>
#include <stddef.h>
#include <sys/cdefs.h>

typedef __UINT64_TYPE__ sigset_t;

int sigdelset(sigset_t *, int);
int sigismember(const sigset_t *, int);
int sigprocmask(int, const sigset_t *restrict, sigset_t *restrict);

int pthread_sigmask(int how, const sigset_t *restrict set, sigset_t *restrict oset)
{
	sigset_t lset;

	if (set != NULL &&
	    (__predict_true(sigismember(set, SIGRTMIN)) || __predict_true(sigismember(set, SIGRTMIN + 1)))) {
		lset = *set;
		sigdelset(&lset, SIGRTMIN);
		sigdelset(&lset, SIGRTMIN + 1);
		set = &lset;
	}

	return sigprocmask(how, set, oset) == -1 ? errno : 0;
}
