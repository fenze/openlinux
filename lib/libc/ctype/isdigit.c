#include <libc.h> // for weak_reference

int isdigit(int c)
{
	return (unsigned)c - '0' < 10;
}

weak_reference(isdigit, isdigit_l);
