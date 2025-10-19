#include <io.h>
#include <unistd.h>
#include <string.h>
#include <atomic.h>
#include <stdio.h>

char __stdin_buffer[BUFSIZ];

size_t fread(void *restrict ptr, size_t size, size_t nitems,
	     FILE *restrict stream)
{
	if (size == 0 || nitems == 0)
		return 0;

	size_t total = size * nitems;
	size_t bytes_read = 0;
	char *p = ptr;

	LIBC_LOCK(stream->lock);

	while (total > 0) {
		if (stream->buf_pos < stream->buf_len) {
			size_t available = stream->buf_len - stream->buf_pos;
			size_t to_copy = total < available ? total : available;

			memcpy(p, stream->buf + stream->buf_pos, to_copy);
			stream->buf_pos += to_copy;
			p += to_copy;
			bytes_read += to_copy;
			total -= to_copy;
			continue;
		}

		ssize_t ret = read(stream->fd, stream->buf, stream->buf_size);
		if (ret <= 0) {
			if (ret < 0)
				stream->flags |= _IO_ERR;
			else
				stream->flags |= _IO_EOF;
			break;
		}

		stream->buf_len = ret;
		stream->buf_pos = 0;
	}

	LIBC_UNLOCK(stream->lock);

	return bytes_read / size;
}
