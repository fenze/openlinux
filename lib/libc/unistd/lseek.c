#include <unistd.h>
#include <syscall.h>

off_t lseek(int fildes, off_t offset, int whence)
{
	return syscall(lseek, fildes, offset, whence);
}
