#include <termios.h>
#include <syscall.h>
#include <asm-generic/ioctls.h>
#include <errno.h>

int tcsetattr(int fildes, int optional_actions, const struct termios *termios_p)
{
	if (optional_actions < 0 || optional_actions > 2) {
		errno = EINVAL;
		return -1;
	}

	return syscall(ioctl, fildes, TCSETS + optional_actions, termios_p);
}
