

#include <signal.h>  // for sigset_t, sigsuspend
#include <syscall.h> // for __syscall_2, syscall

int sigsuspend(const sigset_t *sigmask)
{
	return syscall(rt_sigsuspend, sigmask, sizeof(sigset_t));
}
