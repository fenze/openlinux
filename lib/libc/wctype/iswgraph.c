#include <libc.h>
#include <wctype.h>

int iswgraph(wint_t wc)
{
	return iswprint(wc) && !iswspace(wc);
}

weak int iswgraph_l(wint_t wc, locale_t unused locale)
{
	return iswgraph(wc);
}
