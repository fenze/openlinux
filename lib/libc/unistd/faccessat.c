


#include <syscall.h> // for __syscall_4, syscall

int faccessat(int fd, const char *path, int amode, int flag)
{
	return syscall(faccessat, fd, path, amode, flag);
}
