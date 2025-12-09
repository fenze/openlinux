#include <asm-generic/ioctls.h>
#include <syscall.h>
#include <termios.h>

pid_t tcgetsid(int fildes)
{
	pid_t sid = 0;

	if (syscall(ioctl, fildes, TIOCGSID, &sid) < 0)
		return -1;

	return sid;
}
