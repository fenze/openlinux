#include <libc.h>

int iscntrl(int c)
{
	return (unsigned)c < 0x20 || c == 0x7f;
}

weak_reference(iscntrl, iscntrl_l);
