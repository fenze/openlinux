#include <unistd.h>
#include <syscall.h>

int ftruncate(int fildes, off_t length)
{
	return syscall(ftruncate, fildes, length);
}
