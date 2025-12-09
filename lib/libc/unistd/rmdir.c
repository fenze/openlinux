


#include <syscall.h> // for __syscall_1, syscall

int rmdir(const char *path)
{
	return syscall(rmdir, path);
}
