#include <errno.h>  // for EINVAL, ERANGE
#include <stddef.h> // for NULL, errno_t
#include <string.h> // for rsize_t, memcpy, size_t, memcpy_s
#include <sys/cdefs.h>

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

errno_t memcpy_s(void *restrict dest, rsize_t destsz, const void *restrict src, rsize_t count)
{
	if (dest == NULL || src == NULL) {
		if (dest != NULL && destsz > 0) {
			unsigned char *d = dest;
			for (rsize_t i = 0; i < destsz; i++) {
				d[i] = 0;
			}
		}

		return EINVAL;
	}

	const unsigned char *s = src;
	unsigned char *d = dest;

	if ((d > s && d < s + count) || (s > d && s < d + count)) {
		for (rsize_t i = 0; i < destsz; i++) {
			d[i] = 0;
		}
		return EINVAL;
	}

	if (count > destsz) {
		for (rsize_t i = 0; i < destsz; i++) {
			d[i] = 0;
		}
		return ERANGE;
	}

	for (rsize_t i = 0; i < count; i++) {
		d[i] = s[i];
	}

	return 0;
}
