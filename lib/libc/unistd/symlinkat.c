#include <syscall.h>

int symlinkat(const char *path1, int fd, const char *path2)

{
	return syscall(symlinkat, path1, fd, path2);
}
