#include <libc.h>
#include <ctype.h>

int isalnum(int c)
{
	return isalpha(c) || isdigit(c);
}

weak_reference(isalnum, isalnum_l);
