#include <syscall.h>

int renameat(int oldfd, const char *old, int newfd, const char *new)
{
	return syscall(renameat, oldfd, old, newfd, new);
}
