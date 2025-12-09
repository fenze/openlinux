#include <libc.h> // for weak_reference

int islower(int c)
{
	return (unsigned)c - 'a' < 26;
}

weak_reference(islower, islower_l);
