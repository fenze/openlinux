#include <syscall.h>

int dup2(int fildes, int fildes2)
{
	return syscall(dup2, fildes, fildes2);
}
