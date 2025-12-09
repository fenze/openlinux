#include "asm/unistd_64.h" // for __NR_ioctl

#include <asm-generic/ioctls.h> // for TIOCGWINSZ
#include <syscall.h>		// for __syscall_3, syscall
#include <termios.h>		// for winsize
#include <unistd.h>		// for isatty

int isatty(int fildes)
{
	struct winsize winsize;
	return 1 + syscall(ioctl, fildes, TIOCGWINSZ, &winsize);
}
