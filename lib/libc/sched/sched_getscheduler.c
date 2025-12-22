#include <sched.h>
#include <syscall.h>

int sched_getscheduler(pid_t pid)
{
	return syscall(sched_getscheduler, pid);
}
