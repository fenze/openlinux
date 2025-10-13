#include <unistd.h>
#include <syscall.h>

ssize_t readlinkat(int fd, const char *restrict path, char *restrict buf,
		   size_t bufsize)
{
	return syscall(readlinkat, fd, path, buf, bufsize);
}
