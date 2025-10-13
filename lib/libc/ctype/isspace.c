#include <libc.h>

int isspace(int c)
{
	return c == ' ' || (unsigned)c - '\t' < 5;
}

weak_reference(isspace, isspace_l);
