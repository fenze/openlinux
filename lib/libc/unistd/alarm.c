#include <syscall.h>

unsigned alarm(unsigned seconds)
{
	return syscall(alarm, seconds);
}
