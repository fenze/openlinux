#include <time.h>
#include <syscall.h>

int clock_nanosleep(clockid_t clock_id, int flags, const struct timespec *rqtp,
		    struct timespec *rmtp)
{
	return __syscall(nanosleep, clock_id, flags, rqtp, rmtp) * -1;
}
