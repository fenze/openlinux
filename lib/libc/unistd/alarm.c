

#include <syscall.h> // for __syscall_1, syscall

unsigned alarm(unsigned seconds)
{
	return syscall(alarm, seconds);
}
