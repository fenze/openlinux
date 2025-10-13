#include <libc.h>

int isprint(int c)
{
	return (unsigned)c - 0x20 < 0x5f;
}

weak_reference(isprint, isprint_l);
