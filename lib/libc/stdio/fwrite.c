#include "__stdio.h" // for _IO_ERR
#include "stddef.h"  // for NULL

#include <atomic.h> // for LIBC_UNLOCK, LIBC_LOCK
#include <errno.h>  // for errno, EOVERFLOW, EBADF, EINVAL, EIO
#include <fcntl.h>  // for O_ACCMODE, O_RDONLY
#include <libc.h>   // for __IMPL
#include <stdio.h>  // for fflush, fwrite, BUFSIZ, FILE, _IOFBF, _IOLBF
#include <string.h> // for memcpy, memchr
#include <unistd.h> // for size_t, ssize_t, write

char __stdout_buffer[BUFSIZ];
void (*__stdio_cleanup)(void);

size_t fwrite(const void *restrict ptr, size_t size, size_t nitems,
	      FILE *restrict stream)
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

	if (__IMPL(stream)->fd == -1 && __IMPL(stream)->buf != NULL) {
		if (__builtin_mul_overflow(size, nitems, &total_bytes)) {
			errno = EOVERFLOW;
			return 0;
		}

		size_t space_left =
			__IMPL(stream)->buf_size > __IMPL(stream)->buf_len ?
				__IMPL(stream)->buf_size -
					__IMPL(stream)->buf_len - 1 :
				0;

		if (space_left == 0) {
			return 0;
		}

		size_t to_copy = total_bytes < space_left ? total_bytes :
							    space_left;

		if (to_copy > 0) {
			memcpy(__IMPL(stream)->buf + __IMPL(stream)->buf_len,
			       data, to_copy);
			__IMPL(stream)->buf_len += to_copy;
		}

		return to_copy == total_bytes ? nitems : to_copy / size;
	}

	if (__builtin_mul_overflow(size, nitems, &total_bytes)) {
		errno = EOVERFLOW;
		return 0;
	}

	if ((__IMPL(stream)->flags & O_ACCMODE) == O_RDONLY) {
		errno = EBADF;
		return 0;
	}

	if (__IMPL(stream)->flags & _IO_ERR) {
		errno = EIO;
		return 0;
	}

	LIBC_LOCK(__IMPL(stream)->lock);

	if (__IMPL(stream)->type == _IONBF) {
		ssize_t result = write(__IMPL(stream)->fd, data, total_bytes);
		LIBC_UNLOCK(__IMPL(stream)->lock);

		if (result < 0) {
			__IMPL(stream)->flags |= _IO_ERR;
			return 0;
		}

		return result == (ssize_t)total_bytes ? nitems : result / size;
	}

	size_t remaining = total_bytes;

	while (remaining > 0) {
		size_t space_available =
			__IMPL(stream)->buf_size - __IMPL(stream)->buf_len;

		if (space_available == 0) {
			LIBC_UNLOCK(__IMPL(stream)->lock);
			if (fflush(stream) != 0) {
				return written / size;
			}
			space_available = __IMPL(stream)->buf_size;
		}

		size_t to_copy = remaining < space_available ? remaining :
							       space_available;

		memcpy(__IMPL(stream)->buf + __IMPL(stream)->buf_len,
		       data + written, to_copy);
		__IMPL(stream)->buf_len += to_copy;
		written += to_copy;
		remaining -= to_copy;

		if (__IMPL(stream)->type == _IOLBF) {
			char *newline_pos = memchr(
				__IMPL(stream)->buf + __IMPL(stream)->buf_len -
					to_copy,
				'\n', to_copy);
			if (newline_pos != NULL) {
				LIBC_UNLOCK(__IMPL(stream)->lock);
				if (fflush(stream) != 0) {
					return written / size;
				}
			}
		}

		else if (__IMPL(stream)->type == _IOFBF &&
			 __IMPL(stream)->buf_len == __IMPL(stream)->buf_size) {
			LIBC_UNLOCK(__IMPL(stream)->lock);
			if (fflush(stream) != 0) {
				return written / size;
			}
		}
	}

	LIBC_UNLOCK(__IMPL(stream)->lock);

	return written == total_bytes ? nitems : written / size;
}
