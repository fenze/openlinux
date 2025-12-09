#include <asm-generic/signal.h> // for _NSIG

typedef __UINT64_TYPE__ __sigset_t;

#define __sigmask(sig) (((__sigset_t)1) << ((sig) - 1))
#define __sigismember(set, sig)                     \
	(__extension__({                            \
		__sigset_t __mask = __sigmask(sig); \
		*(set) & __mask ? 1 : 0;            \
	}))

int sigismember(const __sigset_t *set, int signo)
{
	if (signo < 1 || signo > _NSIG)
		return -1;

	return __sigismember((const __sigset_t *)set, signo);
}
