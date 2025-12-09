#include "asm-generic/termbits-common.h"
#include <asm-generic/termbits.h>

speed_t cfgetospeed(const struct termios *termios_p)
{
	return termios_p->c_cflag & CBAUD;
}
