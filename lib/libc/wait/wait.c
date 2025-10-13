#include <sys/wait.h>
#include <syscall.h>

pid_t wait(int *stat_loc)
{
	return syscall(wait4, -1, stat_loc, 0, 0);
}
