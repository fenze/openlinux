
#include <syscall.h> // for __syscall_2, syscall
#include <time.h>    // for clockid_t, clock_getcpuclockid, pid_t

int clock_getcpuclockid(pid_t pid, clockid_t *clock_id)
{
	int ret;
	clockid_t id;
	struct timespec ts;

	id = (clockid_t)((-pid - 1) * 8U + 2);
	ret = syscall(clock_getres, id, &ts);

	if (ret >= 0) {
		*clock_id = id;
	}

	return ret;
}
