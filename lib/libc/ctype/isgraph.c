#include <ctype.h>     // for isgraph, isgraph_l, locale_t
#include <sys/cdefs.h> // for __unused, __weak

int isgraph(int c)
{
	return (unsigned)c - 0x21 < 0x5e;
}

__weak int isgraph_l(int c, locale_t __unused locale)
{
	return isgraph(c);
}
