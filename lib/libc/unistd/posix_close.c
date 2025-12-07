#include <libc.h>
#include <syscall.h>

int posix_close(int fildes, int __unused flag)
{
	return syscall(close, fildes);
}
