


#include <syscall.h> // for __syscall_0, syscall

int pause(void)
{
	return syscall(pause);
}
