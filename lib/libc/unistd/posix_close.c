#include <libc.h>
#include <syscall.h>

int posix_close(int fildes, int unused flag)
{
	return syscall(close, fildes);
}
