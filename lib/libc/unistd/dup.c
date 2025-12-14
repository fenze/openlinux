

#include <syscall.h> // for __syscall_1, syscall

int dup(int fildes)
{
	return syscall(dup, fildes);
}
