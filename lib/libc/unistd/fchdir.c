#include "asm/unistd_64.h" // for __NR_fchdir

#include <syscall.h> // for __syscall_1, syscall

int fchdir(int fildes)
{
	return syscall(fchdir, fildes);
}
