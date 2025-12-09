


#include <signal.h>  // for sigaction, sigset_t
#include <syscall.h> // for __syscall_4, syscall

int sigaction(int sig, const struct sigaction *restrict act,
	      struct sigaction *restrict oact)
{
	return syscall(rt_sigaction, sig, act, oact, sizeof(sigset_t));
}
