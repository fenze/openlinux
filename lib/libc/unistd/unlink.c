#include <syscall.h>

int unlink(const char *path)
{
	return syscall(unlink, path);
}
