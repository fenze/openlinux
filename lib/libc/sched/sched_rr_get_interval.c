#include <sched.h>
#include <syscall.h>

int sched_rr_get_interval(pid_t pid, struct timespec *tp)
{
	return syscall(sched_rr_get_interval, pid, tp);
}
