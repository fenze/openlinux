#include <syscall.h>

int rmdir(const char *path)
{
	return syscall(rmdir, path);
}
