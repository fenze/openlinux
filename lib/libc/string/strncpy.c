#include <stddef.h> // for size_t

char *strncpy(char *restrict s1, const char *restrict s2, size_t n)
{
	char *result = s1;

	while (n > 0 && *s2 != '\0') {
		*s1++ = *s2++;
		n--;
	}

	if (n > 0)
		*s1 = '\0';

	return result;
}
