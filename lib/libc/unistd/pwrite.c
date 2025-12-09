#include <stddef.h>
#include <syscall.h> // for __NR_pwrite, __syscall_4, syscall
#include <unistd.h>  // for off_t, pwrite, size_t, ssize_t

ssize_t pwrite(int fildes, const void *buf, size_t nbyte, off_t offset)
{
	return syscall(pwrite, fildes, buf, nbyte, offset);
}
