#include "asm/unistd_64.h" // for __NR_umount2

#include <syscall.h> // for __syscall_2, syscall

int umount(const char *target)
{
	return syscall(umount2, target, 0);
}
