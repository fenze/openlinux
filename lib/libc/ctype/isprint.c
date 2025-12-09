#include <ctype.h>     // for isprint, isprint_l, locale_t
#include <sys/cdefs.h> // for __unused, __weak

int isprint(int c)
{
	return (unsigned)c - 0x20 < 0x5f;
}

__weak int isprint_l(int c, locale_t __unused locale)
{
	return isprint(c);
}
