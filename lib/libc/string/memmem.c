#include <string.h>

void *memmem(const void *haystack, size_t haystacklen, const void *needle,
	     size_t needlelen)
{
	const unsigned char *p1 = haystack;
	const unsigned char *p2 = needle;
	while (haystacklen >= needlelen) {
		if (!memcmp(p1, p2, needlelen))
			return (void *)p1;
		p1++;
		haystacklen--;
	}
	return NULL;
}
