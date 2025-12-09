


#include <syscall.h> // for __syscall_0, syscall

int munlockall(void)
{
	return syscall(munlockall);
}
