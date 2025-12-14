

#include <signal.h>    // for kill
#include <sys/types.h> // for pid_t
#include <syscall.h>   // for __syscall_2, syscall

int kill(pid_t pid, int sig)
{
	return syscall(kill, pid, sig);
}
