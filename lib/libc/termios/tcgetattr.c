#include <termios.h>
#include <syscall.h>
#include <asm-generic/ioctls.h>

int tcgetattr(int fildes, struct termios *termios_p)

{
	return syscall(ioctl, fildes, TCGETS, termios_p);
}
