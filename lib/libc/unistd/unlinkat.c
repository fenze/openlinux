

#include <syscall.h> // for __syscall_3, syscall

int unlinkat(int fd, const char *path, int flag)
{
	return syscall(unlinkat, fd, path, flag);
}
