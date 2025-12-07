#include <libc.h>
#include <wctype.h>
#include <ctype.h>

int iwsblank(wint_t wc)
{
	return isblank((unsigned char)wc);
}

weak int iswblank_l(wint_t c, locale_t unused locale)
{
	return iswblank(c);
}
