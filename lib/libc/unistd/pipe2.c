


#include <syscall.h> // for __syscall_2, syscall

int pipe2(int fildes[2], int flag)
{
	return syscall(pipe2, fildes, flag);
}
