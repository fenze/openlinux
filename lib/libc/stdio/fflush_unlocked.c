#include <__stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/cdefs.h>
#include <unistd.h>

int fflush_unlocked(struct __FILE *stream)
{
	if (stream == NULL) {
		// TODO: flush all streams
		return 0;
	}

	if (__predict_false(stream->fd) == -1) {
		stream->buf_len = 0;
		return 0;
	}

	if (__predict_false(stream->buf == 0)) {
		return 0;
	}

	if (stream->flags & _IO_ERR) {
		errno = EIO;
		return EOF;
	}

	if ((stream->flags & O_ACCMODE) == O_RDONLY) {
		errno = EBADF;
		return EOF;
	}

	size_t bytes_to_write = stream->buf_len;
	size_t total_written = 0;
	char *buf_ptr = stream->buf;

	while (total_written < bytes_to_write) {
		ssize_t result = write(stream->fd, buf_ptr + total_written, bytes_to_write - total_written);

		if (result < 0) {
			stream->flags |= _IO_ERR;
			return EOF;
		}

		if (result == 0) {
			break;
		}

		total_written += result;
	}

	if (total_written == bytes_to_write) {
		stream->buf_len = 0;
		stream->buf_pos = 0;
	} else {
		size_t remaining = bytes_to_write - total_written;
		memmove(stream->buf, stream->buf + total_written, remaining);
		stream->buf_len = remaining;
		stream->buf_pos = 0;
	}

	return (total_written == bytes_to_write) ? 0 : EOF;
}
