#include <asm-generic/ioctls.h>
#include <syscall.h>
#include <termios.h>

int tcgetattr(int fildes, struct termios *termios_p)

{
	return syscall(ioctl, fildes, TCGETS, termios_p);
}
