#include <syscall.h>

int eventfd(unsigned int initval, int flags)
{
	return syscall(eventfd2, initval, flags);
}
