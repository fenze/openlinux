#include "__stdio.h" // for __FILE, _IO_ERR
#include "stddef.h"  // for NULL

#include <atomic.h> // for LIBC_UNLOCK, LIBC_LOCK
#include <errno.h>  // for errno, EBADF, EIO
#include <fcntl.h>  // for O_ACCMODE, O_RDONLY
#include <stdio.h>  // for EOF, FILE, fflush
#include <string.h> // for memmove
#include <unistd.h> // for size_t, write, ssize_t

int fflush(FILE *stream)
{
	if (stream == NULL) {
		// TODO: Implement flushing all open streams
		// For now, just return success
		return 0;
	}

	if (__FILE(stream)->buf_len == 0) {
		return 0;
	}

	if (__FILE(stream)->fd == -1) {
		__FILE(stream)->buf_len = 0;
		return 0;
	}

	if (__FILE(stream)->flags & _IO_ERR) {
		errno = EIO;
		return EOF;
	}

	if ((__FILE(stream)->flags & O_ACCMODE) == O_RDONLY) {
		errno = EBADF;
		return EOF;
	}

	LIBC_LOCK(__FILE(stream)->lock);

	size_t bytes_to_write = __FILE(stream)->buf_len;
	size_t total_written = 0;
	char *buf_ptr = __FILE(stream)->buf;

	while (total_written < bytes_to_write) {
		ssize_t result = write(__FILE(stream)->fd,
				       buf_ptr + total_written,
				       bytes_to_write - total_written);

		if (result < 0) {
			__FILE(stream)->flags |= _IO_ERR;
			LIBC_UNLOCK(__FILE(stream)->lock);
			return EOF;
		}

		if (result == 0) {
			break;
		}

		total_written += result;
	}

	if (total_written == bytes_to_write) {
		__FILE(stream)->buf_len = 0;
		__FILE(stream)->buf_pos = 0;
	} else {
		size_t remaining = bytes_to_write - total_written;
		memmove(__FILE(stream)->buf,
			__FILE(stream)->buf + total_written, remaining);
		__FILE(stream)->buf_len = remaining;
		__FILE(stream)->buf_pos = 0;
	}

	LIBC_UNLOCK(__FILE(stream)->lock);

	return (total_written == bytes_to_write) ? 0 : EOF;
}
