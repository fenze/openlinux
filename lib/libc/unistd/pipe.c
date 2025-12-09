#include "asm/unistd_64.h" // for __NR_pipe

#include <syscall.h> // for __syscall_1, syscall

int pipe(int fildes[2])
{
	return syscall(pipe, fildes);
}
