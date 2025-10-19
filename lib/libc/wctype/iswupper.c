#include <libc.h>
#include <wctype.h>

int iswupper(wint_t wc)
{
	return towlower(wc) != wc;
}

weak int iswupper_l(wint_t wc, locale_t unused locale)
{
	return iswupper(wc);
}
