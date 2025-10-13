#include <sys/wait.h>
#include <syscall.h>

pid_t waitpid(pid_t pid, int *stat_loc, int options)
{
	return syscall(wait4, pid, stat_loc, options, 0);
}
