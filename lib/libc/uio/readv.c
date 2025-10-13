#include <sys/uio.h>
#include <syscall.h>

ssize_t readv(int fildes, const struct iovec *iov, int iovcnt)
{
	return syscall(readv, fildes, iov, iovcnt);
}
