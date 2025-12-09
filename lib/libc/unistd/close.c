#include "asm/unistd_64.h" // for __NR_close

#include <syscall.h> // for __syscall_1, syscall

int close(int fildes)
{
	return syscall(close, fildes);
}
