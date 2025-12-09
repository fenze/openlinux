#include <syscall.h> // for __NR_pread, __syscall_4, syscall
#include <unistd.h>  // for off_t, pread, size_t, ssize_t

ssize_t pread(int fildes, void *buf, size_t nbyte, off_t offset)
{
	return syscall(pread, fildes, buf, nbyte, offset);
}
