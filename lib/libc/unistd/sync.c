#include <syscall.h>

void sync(void)
{
	syscall(sync);
}
