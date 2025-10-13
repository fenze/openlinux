#include <syscall.h>

int close(int fildes)
{
	return syscall(close, fildes);
}
