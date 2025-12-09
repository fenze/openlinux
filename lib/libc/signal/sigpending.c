


#include <signal.h>  // for sigpending, sigset_t
#include <syscall.h> // for __syscall_1, syscall

int sigpending(sigset_t *set)
{
	return syscall(rt_sigpending, set);
}
