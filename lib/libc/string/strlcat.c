#include <string.h>

size_t strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t dlen = strlen(dst);
	size_t slen = strlen(src);
	size_t n = dstsize - dlen - 1;

	if (n == 0)
		return dlen + slen;

	if (n > slen)
		n = slen;

	memcpy(dst + dlen, src, n);
	dst[dlen + n] = '\0';

	return dlen + n;
}
