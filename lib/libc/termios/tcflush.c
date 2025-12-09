#include <asm-generic/ioctls.h>
#include <syscall.h>
#include <termios.h>

int tcflush(int fildes, int queue_selector)
{
	return syscall(ioctl, fildes, TCFLSH, queue_selector);
}
