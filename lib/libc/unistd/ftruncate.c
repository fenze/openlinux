


#include <syscall.h> // for __syscall_2, syscall
#include <unistd.h>  // for ftruncate, off_t

int ftruncate(int fildes, off_t length)
{
	return syscall(ftruncate, fildes, length);
}
