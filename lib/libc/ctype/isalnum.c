#include <libc.h>
#include <ctype.h>

int isalnum(int c)
{
	return isalpha(c) || isdigit(c);
}

weak int isalnum_l(int c, locale_t unused locale)
{
	return isalnum(c);
}
