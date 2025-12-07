#include <libc.h>
#include <wchar.h>
#include <wctype.h>

int iswspace(wint_t wc)
{
	const wchar_t t[] = { L' ',   L'\t',  L'\n',  L'\r',  11,     12,
			      0x0085, 0x2000, 0x2001, 0x2002, 0x2003, 0x2004,
			      0x2005, 0x2006, 0x2008, 0x2009, 0x200a, 0x2028,
			      0x2029, 0x205f, 0x3000, 0

	};

	return wc && wcschr(t, (wchar_t)wc) != NULL;
}

weak int iswspace_l(wint_t wc, locale_t unused locale)
{
	return iswspace(wc);
}
