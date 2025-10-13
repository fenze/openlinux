#include <libc.h>
#include <ctype.h>

int ispunct(int c)
{
	return isgraph(c) && !isalnum(c);
}

weak_reference(ispunct, ispunct_l);
