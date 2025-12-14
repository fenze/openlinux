

#include <stddef.h>
#include <syscall.h> // for __syscall_3, syscall
#include <unistd.h>  // for readlink, size_t, ssize_t

ssize_t readlink(const char *restrict path, char *restrict buf, size_t bufsize)
{
	return syscall(readlink, path, buf, bufsize);
}
