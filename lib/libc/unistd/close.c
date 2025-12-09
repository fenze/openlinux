


#include <syscall.h> // for __syscall_1, syscall

int close(int fildes)
{
	return syscall(close, fildes);
}
