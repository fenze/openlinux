#include <sched.h>
#include <syscall.h>

int sched_setparam(pid_t pid, const struct sched_param *param)
{
	return syscall(sched_setparam, pid, param);
}
