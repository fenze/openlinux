#include "asm/unistd_64.h" // for __NR_renameat

#include <syscall.h> // for __syscall_4, syscall

int renameat(int oldfd, const char *old, int newfd, const char *new)
{
	return syscall(renameat, oldfd, old, newfd, new);
}
