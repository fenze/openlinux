#include <libc.h>
#include <ctype.h>

int toupper(int c)
{
	if (islower(c))
		return c & 0x5f;
	return c;
}

weak_reference(toupper, toupper_l);
