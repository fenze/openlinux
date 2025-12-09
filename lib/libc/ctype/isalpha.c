#include <ctype.h>     // for isalpha, isalpha_l, locale_t
#include <sys/cdefs.h> // for __unused, __weak

int isalpha(int c)
{
	return ((unsigned)c | 32) - 'a' < 26;
}

__weak int isalpha_l(int c, locale_t __unused locale)
{
	return isalpha(c);
}
