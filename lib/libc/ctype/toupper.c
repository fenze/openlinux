#include <ctype.h>  // for islower, toupper, toupper_l
#include <libc.h>   // for __unused
#include <locale.h> // for locale_t

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
