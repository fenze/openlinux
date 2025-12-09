


#include <syscall.h> // for __syscall_1, syscall

int chdir(const char *path)
{
	return syscall(chdir, path);
}
