#include <syscall.h>

int faccessat(int fd, const char *path, int amode, int flag)
{
	return syscall(faccessat, fd, path, amode, flag);
}
