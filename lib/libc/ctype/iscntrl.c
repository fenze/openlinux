#include <ctype.h>     // for iscntrl, iscntrl_l, locale_t
#include <sys/cdefs.h> // for __unused, __weak

int iscntrl(int c)
{
	return (unsigned)c < 0x20 || c == 0x7f;
}

__weak int iscntrl_l(int c, locale_t __unused locale)
{
	return iscntrl(c);
}
