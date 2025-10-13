#include <fcntl.h>
#include <syscall.h>

int posix_fallocate(int fd, off_t offset, off_t len)
{
	return syscall(fallocate, fd, 0, offset, len);
}
