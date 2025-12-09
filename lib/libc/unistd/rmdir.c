#include "asm/unistd_64.h" // for __NR_rmdir

#include <syscall.h> // for __syscall_1, syscall

int rmdir(const char *path)
{
	return syscall(rmdir, path);
}
