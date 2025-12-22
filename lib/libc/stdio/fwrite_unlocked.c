#include "__stdio.h"
#include <atomic.h>
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

extern void __libc_init_io(void);
void *__libc_force_io_init = (void *)__libc_init_io;

size_t fwrite_unlocked(const void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream)
{
	size_t total_bytes;
	size_t written = 0;
	const char *data = (const char *)ptr;

	if (ptr == NULL || stream == NULL || size == 0) {
		if (size == 0) {
			return nitems;
		}
		errno = EINVAL;
		return 0;
	}

	if (__builtin_mul_overflow(size, nitems, &total_bytes)) {
		errno = EOVERFLOW;
		return 0;
	}

	if ((stream->flags & O_ACCMODE) == O_RDONLY) {
		errno = EBADF;
		return 0;
	}

	if (stream->flags & _IO_ERR) {
		errno = EIO;
		return 0;
	}

	/* Handle in-memory buffer case (e.g., string streams) */
	if (stream->fd == -1 && stream->buf != NULL) {
		size_t space_left = (stream->buf_size > stream->buf_len) ?
					    stream->buf_size - stream->buf_len - 1 /* Reserve for '\0' */
					    :
					    0;
		if (space_left == 0) {
			return 0;
		}
		size_t to_copy = (total_bytes < space_left) ? total_bytes : space_left;
		if (to_copy > 0) {
			memcpy(stream->buf + stream->buf_len, data, to_copy);
			stream->buf_len += to_copy;
		}
		return (to_copy == total_bytes) ? nitems : to_copy / size;
	}

	if (stream->type != _IONBF && stream->buf == NULL) {
		errno = EIO;
		return 0;
	}

	/* Unbuffered mode: direct write */
	if (stream->type == _IONBF) {
		ssize_t result = write(stream->fd, data, total_bytes);
		if (result < 0) {
			stream->flags |= _IO_ERR;
			return 0;
		}
		return (result == (ssize_t)total_bytes) ? nitems : result / size;
	}

	size_t remaining = total_bytes;
	while (remaining > 0) {
		size_t space_available = stream->buf_size - stream->buf_len;
		if (space_available == 0) {
			if (fflush_unlocked(stream) != 0) {
				return written / size;
			}
			space_available = stream->buf_size;
		}
		size_t to_copy = (remaining < space_available) ? remaining : space_available;
		memcpy(stream->buf + stream->buf_len, data + written, to_copy);
		stream->buf_len += to_copy;
		written += to_copy;
		remaining -= to_copy;

		/* Line-buffered: flush on newline in the copied chunk */
		if (stream->type == _IOLBF) {
			char *newline_pos = memchr(stream->buf + stream->buf_len - to_copy, '\n', to_copy);
			if (newline_pos != NULL) {
				if (fflush_unlocked(stream) != 0) {
					return written / size;
				}
			}
		} else if (stream->type == _IOFBF && stream->buf_len == stream->buf_size) {
			/* Full-buffered: flush when buffer is full */
			if (fflush_unlocked(stream) != 0) {
				return written / size;
			}
		}
	}

	return (written == total_bytes) ? nitems : written / size;
}
