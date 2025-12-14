

#include <stddef.h>
#include <syscall.h> // for __syscall_4, syscall
#include <unistd.h>  // for readlinkat, size_t, ssize_t

ssize_t readlinkat(int fd, const char *restrict path, char *restrict buf,
		   size_t bufsize)
{
	return syscall(readlinkat, fd, path, buf, bufsize);
}
