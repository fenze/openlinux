

#include <fcntl.h>     // for posix_fadvise
#include <sys/types.h> // for off_t
#include <syscall.h>   // for __syscall_4, syscall

int posix_fadvise(int fd, off_t offset, off_t len, int advice)
{
	return syscall(fadvise64, fd, offset, len, advice);
}
