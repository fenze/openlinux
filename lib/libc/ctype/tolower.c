#include <libc.h>
#include <ctype.h>

int tolower(int c)
{
	if (isupper(c))
		return c | 32;
	return c;
}

weak int tolower_l(int c, locale_t unused locale)
{
	return tolower(c);
}
