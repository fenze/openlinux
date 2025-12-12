#include <asm-generic/ioctls.h> // for TIOCGWINSZ
#include <syscall.h>		// for __syscall_3, syscall
#include <termios.h>		// for winsize
#include <unistd.h>		// for isatty

int isatty(int fildes)
{
	struct winsize winsize;
	return (int)(1 + syscall(ioctl, fildes, TIOCGWINSZ, &winsize));
}
