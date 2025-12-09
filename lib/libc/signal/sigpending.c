#include "asm/unistd_64.h" // for __NR_rt_sigpending

#include <signal.h>  // for sigpending, sigset_t
#include <syscall.h> // for __syscall_1, syscall

int sigpending(sigset_t *set)
{
	return syscall(rt_sigpending, set);
}
