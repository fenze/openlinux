#include <libc.h>
#include <ctype.h>

int ispunct(int c)
{
	return isgraph(c) && !isalnum(c);
}

weak int ispunct_l(int c, locale_t locale)
{
	return ispunct(c);
}
