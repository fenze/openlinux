#include <syscall.h>

int fdatasync(int fildes)
{
	return syscall(fdatasync, fildes);
}
