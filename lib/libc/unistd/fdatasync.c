


#include <syscall.h> // for __syscall_1, syscall

int fdatasync(int fildes)
{
	return syscall(fdatasync, fildes);
}
