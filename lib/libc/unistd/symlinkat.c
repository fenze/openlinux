#include "asm/unistd_64.h" // for __NR_symlinkat

#include <syscall.h> // for __syscall_3, syscall

int symlinkat(const char *path1, int fd, const char *path2)

{
	return syscall(symlinkat, path1, fd, path2);
}
