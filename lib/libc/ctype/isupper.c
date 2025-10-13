#include <libc.h>

int isupper(int c)
{
	return (unsigned)c - 'A' < 26;
}

weak_reference(isupper, isupper_l);
