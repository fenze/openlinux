#include <ctype.h>     // for islower, toupper, locale_t, toupper_l
#include <sys/cdefs.h> // for __unused

int toupper(int c)
{
	if (islower(c))
		return c & 0x5f;
	return c;
}

int toupper_l(int c, locale_t __unused locale)
{
	return toupper(c);
}
