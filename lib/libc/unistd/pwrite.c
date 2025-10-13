#include <unistd.h>
#include <syscall.h>

ssize_t pwrite(int fildes, const void *buf, size_t nbyte, off_t offset)
{
	return syscall(pwrite, fildes, buf, nbyte, offset);
}
