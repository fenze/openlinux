#include <sys/uio.h>
#include <syscall.h>

ssize_t writev(int fildes, const struct iovec *iov, int iovcnt)
{
	return syscall(writev, fildes, iov, iovcnt);
}
