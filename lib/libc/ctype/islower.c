#include <ctype.h>     // for islower, islower_l, locale_t
#include <sys/cdefs.h> // for __unused, __weak

int islower(int c)
{
	return (unsigned)c - 'a' < 26;
}

__weak int islower_l(int c, locale_t __unused locale)
{
	return islower(c);
}
