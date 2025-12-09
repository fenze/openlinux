


#include <stddef.h>
#include <syscall.h> // for __syscall_3, syscall
#include <unistd.h>  // for read, size_t, ssize_t

ssize_t read(int fildes, void *buf, size_t nbyte)
{
	return syscall(read, fildes, buf, nbyte);
}
