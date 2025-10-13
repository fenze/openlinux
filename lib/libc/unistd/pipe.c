#include <syscall.h>

int pipe(int fildes[2])
{
	return syscall(pipe, fildes);
}
