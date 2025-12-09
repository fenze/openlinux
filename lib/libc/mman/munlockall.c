#include "asm/unistd_64.h" // for __NR_munlockall

#include <syscall.h> // for __syscall_0, syscall

int munlockall(void)
{
	return syscall(munlockall);
}
