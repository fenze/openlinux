#include "__stdio.h"  // for size_t
#include "features.h" // for __weak

#include <libc.h>   // for __unused
#include <locale.h> // for locale_t
#include <string.h> // for strlcpy, strlen, strxfrm, strxfrm_l

size_t strxfrm(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t len = strlen(s2);

	if (n > len)
		strlcpy(s1, s2, n);

	return len;
}

__weak size_t strxfrm_l(char *restrict s1, const char *restrict s2, size_t n,
			locale_t __unused locale)
{
	return strxfrm(s1, s2, n);
}
