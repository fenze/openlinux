#include <libc.h>
#include <ctype.h>

int tolower(int c)
{
	if (isupper(c))
		return c | 32;
	return c;
}

weak_reference(tolower, tolower_l);
