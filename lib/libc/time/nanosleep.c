#include <time.h>
#include <syscall.h>

int nanosleep(const struct timespec *rqtp, struct timespec *rmtp)
{
	return syscall(nanosleep, rqtp, rmtp);
}
