


#include <syscall.h> // for __syscall_1, syscall

int unlink(const char *path)
{
	return syscall(unlink, path);
}
