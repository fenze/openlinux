

#include <syscall.h> // for __syscall_1, syscall

int fsync(int fildes)
{
	return syscall(fsync, fildes);
}
