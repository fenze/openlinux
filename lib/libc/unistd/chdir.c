#include <syscall.h>

int chdir(const char *path)
{
	return syscall(chdir, path);
}
