

#include <syscall.h> // for __syscall_4, syscall

int renameat(int oldfd, const char *old, int newfd, const char *new)
{
	return syscall(renameat, oldfd, old, newfd, new);
}
