#include <syscall.h>

int access(const char *path, int amode)
{
	return syscall(access, path, amode);
}
