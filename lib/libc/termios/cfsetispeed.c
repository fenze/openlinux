#include <errno.h>
#include <asm-generic/termbits.h>

int cfsetispeed(struct termios *termios_p, speed_t speed)
{
	if (speed & ~CBAUD) {
		errno = EINVAL;
		return -1;
	}

	termios_p->c_cflag &= ~CIBAUD;
	termios_p->c_cflag |= speed * (CIBAUD / CBAUD);
	return 0;
}
