#include <ctype.h>     // for isspace, isspace_l, locale_t
#include <sys/cdefs.h> // for __unused, __weak

int isspace(int c)
{
	return c == ' ' || (unsigned)c - '\t' < 5;
}

__weak int isspace_l(int c, locale_t __unused locale)
{
	return isspace(c);
}
