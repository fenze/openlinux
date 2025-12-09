#include <stddef.h> // for NULL, size_t

void *memchr(const void *s, int c, size_t n)
{
	const unsigned char *p = s;
	while (n--) {
		if (*p == (unsigned char)c)
			return (void *)p;
		p++;
	}
	return NULL;
}
