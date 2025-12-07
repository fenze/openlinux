#include <signal.h>
#include <syscall.h>

int sigsuspend(const sigset_t *sigmask)
{
	return syscall(rt_sigsuspend, sigmask, sizeof(sigset_t));
}
