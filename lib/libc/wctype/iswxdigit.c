#include <libc.h>
#include <wctype.h>

int iswxdigit(wint_t wc)
{
	return (unsigned)(wc - '0') < 10 || (unsigned)((wc | 32) - 'a') < 6;
}

weak int iswxdigit_l(wint_t wc, locale_t unused locale)
{
	return iswxdigit(wc);
}
