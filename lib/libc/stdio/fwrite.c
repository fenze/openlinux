#include <io.h>
#include <atomic.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

size_t fwrite(const void *restrict ptr, size_t size, size_t nitems,
	      FILE *restrict stream)
{
	size_t k, l;

	if (__builtin_mul_overflow(size, nitems, &k)) {
		errno = EOVERFLOW;
		return 0;
	}

	if (size == 0)
		nitems = 0;

	LIBC_LOCK(stream->lock);

	if (stream->type & _IONBF) {
		l = write(stream->fd, ptr, k);
		if (l == (size_t)-1) {
			stream->flags |= _IO_ERR;
			LIBC_UNLOCK(stream->lock);
			return 0;
		}
	} else {
		l = 0;
		while (l < k) {
			if (stream->buf_pos == stream->buf_size) {
				if (fflush(stream) == -1) {
					LIBC_UNLOCK(stream->lock);
					return l / size;
				}
			}
			size_t to_copy = stream->buf_size - stream->buf_pos;
			if (to_copy > k - l)
				to_copy = k - l;
			memcpy(stream->buf + stream->buf_pos,
			       (unsigned char *)ptr + l, to_copy);
			stream->buf_pos += to_copy;
			l += to_copy;
			if ((stream->type & _IOLBF) &&
			    memchr((unsigned char *)ptr + l - to_copy, '\n',
				   to_copy)) {
				if (fflush(stream) == -1) {
					LIBC_UNLOCK(stream->lock);
					return l / size;
				}
			}
		}
	}

	LIBC_UNLOCK(stream->lock);
	return k == l ? nitems : k / size;
}
