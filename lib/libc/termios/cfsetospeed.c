#include "asm-generic/termbits-common.h"
#include <asm-generic/termbits.h>
#include <errno.h>

int cfsetospeed(struct termios *termios_p, speed_t speed)
{
	if (speed & ~CBAUD) {
		errno = EINVAL;
		return -1;
	}
	termios_p->c_cflag &= ~CBAUD;
	termios_p->c_cflag |= speed;
	return 0;
}
