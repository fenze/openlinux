#include <string.h>
#include <features.h>

__weak void *memcpy(void *restrict s1, const void *restrict s2, size_t n);

void *memcpy(void *restrict s1, const void *restrict s2, size_t n)
{
	unsigned char *dest = (unsigned char *)s1;
	const unsigned char *src = (const unsigned char *)s2;

	while (n--) {
		*dest++ = *src++;
	}

	return s1;
}
