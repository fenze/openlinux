#include "asm/unistd_64.h" // for __NR_unlink

#include <syscall.h> // for __syscall_1, syscall

int unlink(const char *path)
{
	return syscall(unlink, path);
}
