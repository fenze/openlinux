#include <unistd.h>
#include <syscall.h>

int nice(int incr)
{
	(void)incr;
	// TODO: needs getpriority and setpriority from sys/resouce.h
	return 0;
}
