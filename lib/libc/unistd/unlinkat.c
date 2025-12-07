#include <syscall.h>

int unlinkat(int fd, const char *path, int flag)
{
	return syscall(unlinkat, fd, path, flag);
}
