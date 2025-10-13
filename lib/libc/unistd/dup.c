#include <syscall.h>

int dup(int fildes)
{
	return syscall(dup, fildes);
}
