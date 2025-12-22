#include "__stdio.h" // for __FILE, _IO_EOF, _IO_ERR
#include "stddef.h"  // for NULL

#include <atomic.h> // for LIBC_LOCK, LIBC_UNLOCK
#include <stdio.h>  // for FILE, fseek
#include <unistd.h> // for lseek, off_t

int fseek(FILE *stream, long offset, int whence)
{
	if (stream == NULL || stream->fd < 0)
		return -1;

	stream->buf_pos = 0;
	stream->buf_len = 0;
	stream->flags &= ~_IO_EOF;

	off_t result = lseek(stream->fd, offset, whence);

	if (result == (off_t)-1) {
		stream->flags |= _IO_ERR;
		return -1;
	}

	stream->offset = result;

	return 0;
}
