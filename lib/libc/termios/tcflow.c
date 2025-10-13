#include <asm-generic/ioctls.h>
#include <syscall.h>

int tcflow(int fildes, int action)
{
	return syscall(ioctl, fildes, TCXONC, action);
}
