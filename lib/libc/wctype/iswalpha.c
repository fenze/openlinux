#include <libc.h>
#include <wctype.h>

int iswalpha(wint_t wc)
{
	const unsigned char t[] = {
#include <__alpha.h>
	};

	if (wc < 0x20000U)
		return (t[t[wc >> 8] * 32 + ((wc & 255) >> 3)] >> (wc & 7)) & 1;

	if (wc < 0x2fffeU)
		return 1;

	return 0;
}

weak int iswalpha_l(wint_t wc, locale_t unused locale)
{
	return iswalpha(wc);
}
