#include <errno.h>
#include <limits.h>
#include <sys/resource.h>
#include <unistd.h>

int nice(int incr)
{
	int priority = incr;

	if (incr > NZERO * -2 && incr < NZERO * 2) {
		priority += getpriority(PRIO_PROCESS, 0);
	}

	if (priority > NZERO - 1)
		priority = NZERO - 1;

	if (priority < -NZERO)
		priority = -NZERO;

	if (setpriority(PRIO_PROCESS, 0, priority)) {
		if (errno == EACCES)
			errno = EPERM;

		return -1;
	}

	return priority;
}
