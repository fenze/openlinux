#include <sched.h>
#include <syscall.h>

int sched_setscheduler(pid_t pid, int policy, const struct sched_param *param)
{
	return syscall(sched_setscheduler, pid, policy, param);
}
