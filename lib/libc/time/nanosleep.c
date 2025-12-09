

#include <syscall.h> // for __syscall_2, syscall
#include <time.h>    // for nanosleep

int nanosleep(const struct timespec *rqtp, struct timespec *rmtp)
{
	return syscall(nanosleep, rqtp, rmtp);
}
