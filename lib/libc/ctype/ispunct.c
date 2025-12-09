#include "features.h" // for __weak

#include <ctype.h>  // for isalnum, isgraph, ispunct, ispunct_l
#include <libc.h>   // for __unused
#include <locale.h> // for locale_t

int ispunct(int c)
{
	return isgraph(c) && !isalnum(c);
}

__weak int ispunct_l(int c, locale_t __unused locale)
{
	return ispunct(c);
}
