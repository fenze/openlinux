#include <time.h>
#include <syscall.h>

int clock_getres(clockid_t clock_id, struct timespec *res)
{
	return syscall(clock_getres, clock_id, res);
}
