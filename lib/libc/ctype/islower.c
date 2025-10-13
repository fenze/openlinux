#include <libc.h>

int islower(int c)
{
	return (unsigned)c - 'a' < 26;
}

weak_reference(islower, islower_l);
