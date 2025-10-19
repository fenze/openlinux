#include <signal.h>
#include <syscall.h>

int sigpending(sigset_t *set)
{
	return syscall(rt_sigpending, set);
}
