#include <termios.h>
#include <syscall.h>
#include <asm-generic/ioctls.h>

int tcflush(int fildes, int queue_selector)
{
	return syscall(ioctl, fildes, TCFLSH, queue_selector);
}
