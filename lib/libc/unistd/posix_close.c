#include "asm/unistd_64.h" // for __NR_close

#include <libc.h>    // for __unused
#include <syscall.h> // for __syscall_1, syscall

int posix_close(int fildes, int __unused flag)
{
	return syscall(close, fildes);
}
