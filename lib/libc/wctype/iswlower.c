#include <libc.h>
#include <wctype.h>

int iswlower(wint_t wc)
{
	return towupper(wc) != wc;
}

weak int islower_l(wint_t wc, locale_t unused locale)
{
	return iswlower(wc);
}
