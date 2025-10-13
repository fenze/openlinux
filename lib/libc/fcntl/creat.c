#include <fcntl.h>
#include <syscall.h>

int creat(const char *path, mode_t mode)
{
	return syscall(creat, path, mode);
}
