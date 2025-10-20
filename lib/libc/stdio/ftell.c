#include <stdio.h>
#include <limits.h>
#include <errno.h>

long ftell(FILE *stream)
{
	off_t pos;

	if ((pos = ftello(stream)) > LONG_MAX) {
		errno = EOVERFLOW;
		return -1;
	}

	return pos;
}
