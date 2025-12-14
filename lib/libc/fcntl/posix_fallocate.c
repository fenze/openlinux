

#include <fcntl.h>     // for posix_fallocate
#include <sys/types.h> // for off_t
#include <syscall.h>   // for __syscall_4, syscall

int posix_fallocate(int fd, off_t offset, off_t len)
{
	return syscall(fallocate, fd, 0, offset, len);
}
