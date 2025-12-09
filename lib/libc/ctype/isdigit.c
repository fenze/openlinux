#include <ctype.h>     // for isdigit, isdigit_l, locale_t
#include <sys/cdefs.h> // for __unused, __weak

int isdigit(int c)
{
	return (unsigned)c - '0' < 10;
}

__weak int isdigit_l(int c, locale_t __unused locale)
{
	return isdigit(c);
}
