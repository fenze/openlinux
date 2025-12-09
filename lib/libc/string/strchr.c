#include "stddef.h" // for NULL

#include <string.h> // for strchr

char *strchr(const char *s, int c)
{
	while (*s) {
		if (*s == (char)c)
			return (char *)s;
		s++;
	}
	if (c == 0)
		return (char *)s;
	return NULL;
}
