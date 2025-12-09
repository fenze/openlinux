#include <stdint.h> // for uint8_t, uintptr_t
#include <string.h> // for size_t, memmove

void *memmove(void *dst, const void *src, size_t n)
{
	uint8_t *d = dst;
	const uint8_t *s = src;

	if (d == s || n == 0)
		return dst;

	if ((uintptr_t)d < (uintptr_t)s) {
		for (size_t i = 0; i < n; i++)
			d[i] = s[i];
	} else {
		for (size_t i = n; i != 0; i--)
			d[i - 1] = s[i - 1];
	}

	return dst;
}
