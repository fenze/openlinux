#include <unistd.h>
#include <syscall.h>

ssize_t pread(int fildes, void *buf, size_t nbyte, off_t offset)
{
	return syscall(pread, fildes, buf, nbyte, offset);
}
