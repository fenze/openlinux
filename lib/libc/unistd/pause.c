#include <syscall.h>

int pause(void)
{
	return syscall(pause);
}
