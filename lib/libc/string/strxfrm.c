#include <string.h>

size_t strxfrm(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t len = strlen(s2);

	if (n > len)
		strcpy(s1, s2);

	return len;
}
