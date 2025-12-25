#include <errno.h>  // for EINVAL, ERANGE
#include <stddef.h> // for NULL, errno_t
#include <stdint.h>
#include <string.h> // for rsize_t, memcpy, size_t, memcpy_s
#include <sys/cdefs.h>

__weak void *memcpy(void *restrict s1, const void *restrict s2, size_t n);

void *memcpy(void *restrict s1, const void *restrict s2, size_t n)
{
	unsigned char *d = (unsigned char *)s1;
	const unsigned char *s = (const unsigned char *)s2;

	if (n == 0)
		return s1;

	if (n < 16) {
		if (n >= 8) {
			*(uint64_t *)d = *(const uint64_t *)s;
			d += 8;
			s += 8;
			n -= 8;
		}
		if (n >= 4) {
			*(uint32_t *)d = *(const uint32_t *)s;
			d += 4;
			s += 4;
			n -= 4;
		}
		if (n >= 2) {
			*(uint16_t *)d = *(const uint16_t *)s;
			d += 2;
			s += 2;
			n -= 2;
		}
		if (n)
			*d = *s;
		return s1;
	}

	uintptr_t align_mask = 15;
	size_t misalign = (uintptr_t)d & align_mask;
	if (misalign) {
		size_t to_align = 16 - misalign;
		if (to_align > n)
			to_align = n;
		for (size_t i = 0; i < to_align; ++i)
			*d++ = *s++;
		n -= to_align;
	}

	while (n >= 128) {
#pragma unroll
		for (int i = 0; i < 8; ++i) {
			((i128 *)d)[i] = ((const i128 *)s)[i];
		}
		d += 128;
		s += 128;
		n -= 128;
	}
	while (n >= 64) {
#pragma unroll
		for (int i = 0; i < 4; ++i) {
			((i128 *)d)[i] = ((const i128 *)s)[i];
		}
		d += 64;
		s += 64;
		n -= 64;
	}
	while (n >= 32) {
#pragma unroll
		for (int i = 0; i < 2; ++i) {
			((i128 *)d)[i] = ((const i128 *)s)[i];
		}
		d += 32;
		s += 32;
		n -= 32;
	}
	while (n >= 16) {
		*(i128 *)d = *(const i128 *)s;
		d += 16;
		s += 16;
		n -= 16;
	}

	if (n >= 8) {
		*(uint64_t *)d = *(const uint64_t *)s;
		d += 8;
		s += 8;
		n -= 8;
	}
	if (n >= 4) {
		*(uint32_t *)d = *(const uint32_t *)s;
		d += 4;
		s += 4;
		n -= 4;
	}
	if (n >= 2) {
		*(uint16_t *)d = *(const uint16_t *)s;
		d += 2;
		s += 2;
		n -= 2;
	}
	if (n)
		*d = *s;

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
