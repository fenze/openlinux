#include <libc.h>
#include <ctype.h>

int ispunct(int c)
{
	return isgraph(c) && !isalnum(c);
}

__weak int ispunct_l(int c, locale_t __unused locale)
{
	return ispunct(c);
}
