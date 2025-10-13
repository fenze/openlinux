#include <syscall.h>

int dup3(int fildes, int fildes2, int flag)
{
	return syscall(dup3, fildes, fildes2, flag);
}
