#include <libc.h> // for weak_reference

int isupper(int c)
{
	return (unsigned)c - 'A' < 26;
}

weak_reference(isupper, isupper_l);
