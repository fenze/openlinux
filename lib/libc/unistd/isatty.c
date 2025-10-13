#include <termios.h>
#include <unistd.h>
#include <syscall.h>
#include <asm-generic/ioctls.h>

int isatty(int fildes)
{
	struct winsize winsize;
	return 1 + syscall(ioctl, fildes, TIOCGWINSZ, &winsize);
}
