

#include <stddef.h>
#include <syscall.h> // for __syscall_3, syscall
#include <unistd.h>  // for size_t, ssize_t, write

ssize_t write(int fd, const void *buf, size_t count)
{
	return syscall(write, fd, buf, count);
}
