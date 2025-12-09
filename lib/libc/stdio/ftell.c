#include <errno.h>     // for EOVERFLOW, errno
#include <limits.h>    // for LONG_MAX
#include <stdio.h>     // for ftello, FILE, ftell
#include <sys/types.h> // for off_t

long ftell(FILE *stream)
{
	off_t pos;

	if ((pos = ftello(stream)) > LONG_MAX) {
		errno = EOVERFLOW;
		return -1;
	}

	return pos;
}
