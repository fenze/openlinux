#include "asm/unistd_64.h" // for __NR_fsync

#include <syscall.h> // for __syscall_1, syscall

int fsync(int fildes)
{
	return syscall(fsync, fildes);
}
