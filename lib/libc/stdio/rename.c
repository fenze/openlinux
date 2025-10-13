#include <syscall.h>

int rename(const char *old, const char *new)
{
	return syscall(rename, old, new);
}
