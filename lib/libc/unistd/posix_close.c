#include <syscall.h>

int posix_close(int fildes, int flag)
{
	(void)flag;

	return syscall(close, fildes);
}
