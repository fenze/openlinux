#include <time.h>
#include <syscall.h>

int clock_getcpuclockid(pid_t pid, clockid_t *clock_id)
{
	int ret;
	clockid_t id;
	struct timespec ts;

	id = (-pid - 1) * 8U + 2;
	ret = syscall(clock_getres, id, &ts);

	if (ret >= 0) {
		*clock_id = id;
	}

	return ret;
}
