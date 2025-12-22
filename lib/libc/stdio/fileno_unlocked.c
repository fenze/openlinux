#include <__stdio.h>
#include <errno.h>
#include <stdio.h>

int fileno_unlocked(FILE *stream)
{
	if (stream->fd < 0) {
		errno = EBADF;
		return -1;
	}

	return stream->fd;
}
