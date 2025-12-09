#include <ctype.h>     // for isblank, isblank_l, locale_t
#include <sys/cdefs.h> // for __unused, __weak

int isblank(int c)
{
	return (c == ' ' || c == '\t');
}

__weak int isblank_l(int c, locale_t __unused locale)
{
	return isblank(c);
}
