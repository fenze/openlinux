

#include <syscall.h> // for __syscall_2, syscall
#include <time.h>    // for clock_getres, clockid_t

int clock_getres(clockid_t clock_id, struct timespec *res)
{
	return syscall(clock_getres, clock_id, res);
}
