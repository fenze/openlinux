#include <libc.h>
#include <wctype.h>

int iswprint(wint_t wc)
{
	return (wc >= 0x20 && wc <= 0x7E) ||
	       (wc >= 0xA0 && wc <= 0x10FFFF && (wc < 0xFDD0 || wc > 0xFDEF) &&
		(wc & 0xFFFE) != 0xFFFE);
}

weak int iswprint_l(wint_t wc, locale_t unused locale)
{
	return iswprint(wc);
}
