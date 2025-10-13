#include <stddef.h>

void *memccpy(void *restrict s1, const void *restrict s2, int c, size_t n)
{
	const unsigned char *p2 = s2;
	unsigned char *p1 = s1;
	while (n--) {
		if (*p2 == (unsigned char)c)
			return p1 + 1;
		*p1++ = *p2++;
	}
	return NULL;
}
