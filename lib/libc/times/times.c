#include <sys/times.h>
#include <syscall.h>

clock_t times(struct tms *buffer)
{
	return syscall(times, buffer);
}
