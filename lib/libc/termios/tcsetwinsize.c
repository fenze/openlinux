#include <asm-generic/ioctls.h>
#include <syscall.h>
#include <termios.h>

int tcsetwinsize(int fildes, const struct winsize *winsize_p)
{
	return syscall(ioctl, fildes, TIOCSWINSZ, winsize_p);
}
