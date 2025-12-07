#include <syscall.h>

int fsync(int fildes)
{
	return syscall(fsync, fildes);
}
