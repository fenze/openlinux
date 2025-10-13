#include <syscall.h>

int symlink(const char *path1, const char *path2)
{
	return syscall(symlink, path1, path2);
}
