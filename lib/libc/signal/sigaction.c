#include <signal.h>
#include <syscall.h>

int sigaction(int sig, const struct sigaction *restrict act,
	      struct sigaction *restrict oact)
{
	return syscall(rt_sigaction, sig, act, oact, sizeof(sigset_t));
}
