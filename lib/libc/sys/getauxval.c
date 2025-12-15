#include <errno.h>
#include <libc.h>

unsigned long getauxval(unsigned long type)
{
	size_t *auxv = __libc.auxv;

	while (*auxv) {
		if (*auxv == type)
			return auxv[1];
		auxv += 2;
	}

	errno = ENOENT;
	return 0;
}
