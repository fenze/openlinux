#include <ctype.h>     // for isalpha, isdigit, isalnum, isalnum_l, locale_t
#include <sys/cdefs.h> // for __unused, __weak

int isalnum(int c)
{
	return isalpha(c) || isdigit(c);
}

__weak int isalnum_l(int c, locale_t __unused locale)
{
	return isalnum(c);
}
