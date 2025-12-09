#include "asm/unistd_64.h" // for __NR_sync

#include <syscall.h> // for __syscall_0, syscall

void sync(void)
{
	syscall(sync);
}
