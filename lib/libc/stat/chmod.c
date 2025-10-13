#include <sys/stat.h>
#include <syscall.h>

int chmod(const char *path, mode_t mode)
{
	return syscall(chmod, path, mode);
}
