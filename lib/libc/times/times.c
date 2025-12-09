#include <sys/times.h>
#include <syscall.h>
#include <time.h>

clock_t times(struct tms *buffer)
{
	return syscall(times, buffer);
}
