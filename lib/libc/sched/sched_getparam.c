#include <errno.h>
#include <sched.h>
#include <sys/cdefs.h>

int sched_getparam(pid_t __unused pid, struct sched_param *__unused param)
{
	errno = ENOSYS;
	return -1;
}
