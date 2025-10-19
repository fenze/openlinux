#include <libc.h>
#include <wctype.h>

int iswdigit(wint_t wc)
{
	return (wc >= L'0' && wc <= L'9');
}

weak int iswdigit_l(wint_t wc, locale_t unused locale)
{
	return iswdigit(wc);
}
