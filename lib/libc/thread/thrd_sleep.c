#include <errno.h>
#include <syscall.h>
#include <threads.h>
#include <time.h>

int thrd_sleep(const struct timespec *duration, struct timespec *remaining)
{
	int r = __syscall(nanosleep, CLOCK_REALTIME, 0, duration, remaining);

	if (r == 0)
		return 0;

	if (r == EINTR)
		return -1;

	return -2;
}
