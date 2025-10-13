#include <unistd.h>
#include <io.h>
#include <stdio.h>
#include <atomic.h>

int fseek(FILE *stream, long offset, int whence)
{
	if (stream == NULL || stream->fd < 0)
		return -1;

	LIBC_LOCK(stream->lock);

	stream->buf_pos = 0;
	stream->buf_len = 0;
	stream->flags &= ~_IO_EOF;

	off_t result = lseek(stream->fd, offset, whence);

	LIBC_UNLOCK(stream->lock);

	if (result == (off_t)-1) {
		stream->flags |= _IO_ERR;
		return -1;
	}

	stream->offset = result;
	return 0;
}
