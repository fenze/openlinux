#include <unistd.h> // for nice

int nice(int incr)
{
	(void)incr;
	// TODO: needs getpriority and setpriority from sys/resouce.h
	return 0;
}
