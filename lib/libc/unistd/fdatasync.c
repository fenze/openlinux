#include "asm/unistd_64.h" // for __NR_fdatasync

#include <syscall.h> // for __syscall_1, syscall

int fdatasync(int fildes)
{
	return syscall(fdatasync, fildes);
}
