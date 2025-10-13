#include <syscall.h>

int pipe2(int fildes[2], int flag)
{
	return syscall(pipe2, fildes, flag);
}
