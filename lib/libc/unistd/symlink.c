#include "asm/unistd_64.h" // for __NR_symlink

#include <syscall.h> // for __syscall_2, syscall

int symlink(const char *path1, const char *path2)
{
	return syscall(symlink, path1, path2);
}
