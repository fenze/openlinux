#include "features.h" // for __weak

#include <ctype.h>  // for isalnum, isalpha, isdigit, isalnum_l
#include <libc.h>   // for __unused
#include <locale.h> // for locale_t

int isalnum(int c)
{
	return isalpha(c) || isdigit(c);
}

__weak int isalnum_l(int c, locale_t __unused locale)
{
	return isalnum(c);
}
