#include <asm-generic/termbits.h>

speed_t cfgetispeed(const struct termios *termios_p)
{
	return (termios_p->c_cflag & CIBAUD) / (CIBAUD / CBAUD);
}
