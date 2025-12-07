#include <libc.h>
#include <wctype.h>

int iswalnum(wint_t wc)
{
	return iswdigit(wc) || iswalpha(wc);
}

weak int iswalnum_l(wint_t wc, locale_t unused locale)
{
	return iswalnum(wc);
}
