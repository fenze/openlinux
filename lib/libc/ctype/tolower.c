#include <ctype.h>     // for isupper, tolower, tolower_l
#include <locale.h>    // for locale_t
#include <sys/cdefs.h> // for __unused, __weak

int tolower(int c)
{
	if (isupper(c))
		return c | 32;
	return c;
}

__weak int tolower_l(int c, locale_t __unused locale)
{
	return tolower(c);
}
