


#include <syscall.h> // for __syscall_2, syscall

int access(const char *path, int amode)
{
	return syscall(access, path, amode);
}
