#include <unistd.h> // for ssize_t, swab

void swab(const void *restrict src, void *restrict dest, ssize_t nbytes)
{
	const char *s = src;
	char *d = dest;

	if (nbytes <= 0)
		return;

	ssize_t n = nbytes & ~1;

	for (ssize_t i = 0; i < n; i += 2) {
		d[i] = s[i + 1];
		d[i + 1] = s[i];
	}
}
