#include <string.h> // for strncpy, size_t

char *strncpy(char *restrict s1, const char *restrict s2, size_t n)
{
	char *d = s1;

	while (n-- && *s2)
		*d++ = *s2++;

	while (n--)
		*d++ = '\0';

	return s1;
}
