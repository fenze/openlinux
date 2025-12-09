#include <libc.h> // for weak_reference

int isspace(int c)
{
	return c == ' ' || (unsigned)c - '\t' < 5;
}

weak_reference(isspace, isspace_l);
