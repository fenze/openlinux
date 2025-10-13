#include <syscall.h>

int fchdir(int fildes)
{
	return syscall(fchdir, fildes);
}
