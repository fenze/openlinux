

#include <signal.h>  // for siginfo_t, sigset_t, sigtimedwait
#include <syscall.h> // for __syscall_4, syscall
#include <time.h>

struct timespec;

#define _NSIG 64

int sigtimedwait(const sigset_t *restrict set, siginfo_t *restrict info,
		 const struct timespec *restrict timeout)
{
	return syscall(rt_sigtimedwait, set, info, timeout, _NSIG / 8);
}
