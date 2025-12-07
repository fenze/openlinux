#include <libc.h>
#include <ctype.h>

int isalnum(int c)
{
	return isalpha(c) || isdigit(c);
}

__weak int isalnum_l(int c, locale_t __unused locale)
{
	return isalnum(c);
}
