#include "asm/unistd_64.h" // for __NR_pause

#include <syscall.h> // for __syscall_0, syscall

int pause(void)
{
	return syscall(pause);
}
