

#include <syscall.h> // for __syscall_1, syscall

int pipe(int fildes[2])
{
	return syscall(pipe, fildes);
}
