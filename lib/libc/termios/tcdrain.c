#include <asm-generic/ioctls.h>
#include <syscall.h>

int tcdrain(int fildes)
{
	return syscall(ioctl, fildes, TCSBRK, 1);
}
