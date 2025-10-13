#include <fcntl.h>
#include <syscall.h>

int posix_fadvise(int fd, off_t offset, off_t len, int advice)
{
	return syscall(fadvise64, fd, offset, len, advice);
}
