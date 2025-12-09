#include <ctype.h>     // for isupper, isupper_l, locale_t
#include <sys/cdefs.h> // for __unused, __weak

int isupper(int c)
{
	return (unsigned)c - 'A' < 26;
}

__weak int isupper_l(int c, locale_t __unused locale)
{
	return isupper(c);
}
