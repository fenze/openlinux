#include <termios.h>
#include <syscall.h>
#include <asm-generic/ioctls.h>

int tcsetwinsize(int fildes, const struct winsize *winsize_p)
{
	return syscall(ioctl, fildes, TIOCSWINSZ, winsize_p);
}
