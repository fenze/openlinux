#include <io.h>
#include <errno.h>
#include <atomic.h>
#include <stdio.h>

int fileno(FILE *stream)
{
	int fd;

	LIBC_LOCK(stream->lock);
	fd = stream->fd;
	LIBC_UNLOCK(stream->lock);

	if (fd < 0) {
		errno = EBADF;
		return -1;
	}

	return fd;
}
