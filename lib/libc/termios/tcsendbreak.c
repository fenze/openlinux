#include <termios.h>
#include <syscall.h>
#include <asm-generic/ioctls.h>

int tcsendbreak(int fildes, int duration)
{
	// IEEE Std 1003.1-2024
	// If duration is not 0, it shall send zero-valued
	// bits for an implementation-defined period of time.
	return syscall(ioctl, fildes, TCSBRK, 0);
}
