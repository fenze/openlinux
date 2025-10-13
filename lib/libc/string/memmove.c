#include <stddef.h>

void *memmove(void *s1, const void *s2, size_t n)
{
	char *d = s1;
	const char *s = s2;

	if (d < s) {
		while (n--)
			*d++ = *s++;
	} else if (d > s) {
		d += n;
		s += n;
		while (n--)
			*--d = *--s;
	}
	return s1;
}
