#include <errno.h>
#include <libc.h>

#include <stdio.h>

unsigned long getauxval(unsigned long type)
{
	size_t *p = __libc.auxv;

	while (*p != 0) {
		if (*p == type)
			return p[1];
		p += 2;
	}

	errno = ENOENT;
	return 0;
}
