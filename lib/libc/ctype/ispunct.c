#include <ctype.h>     // for isalnum, isgraph, ispunct, ispunct_l
#include <locale.h>    // for locale_t
#include <sys/cdefs.h> // for __unused, __weak

int ispunct(int c)
{
	return isgraph(c) && !isalnum(c);
}

__weak int ispunct_l(int c, locale_t __unused locale)
{
	return ispunct(c);
}
