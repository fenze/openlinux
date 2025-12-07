#include <string.h>

char *strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	char *dest = s1;
	const char *src = s2;

	while (*dest != '\0')
		dest++;

	while (*src != '\0' && n > 0) {
		*dest++ = *src++;
		n--;
	}

	*dest = '\0';

	return s1;
}
