#include "__stdio.h" // for __FILE, _IO_EOF, _IO_ERR

#include <atomic.h> // for LIBC_LOCK, LIBC_UNLOCK
#include <stdio.h>  // for fread, BUFSIZ, FILE
#include <string.h> // for memcpy
#include <unistd.h> // for size_t, read, ssize_t

char __stdin_buffer[BUFSIZ];

size_t fread(void *restrict ptr, size_t size, size_t nitems,
	     FILE *restrict stream)
{
	if (size == 0 || nitems == 0)
		return 0;

	size_t total = size * nitems;
	size_t bytes_read = 0;
	char *p = ptr;

	LIBC_LOCK(__FILE(stream)->lock);

	while (total > 0) {
		if (__FILE(stream)->buf_pos < __FILE(stream)->buf_len) {
			size_t available = __FILE(stream)->buf_len -
					   __FILE(stream)->buf_pos;
			size_t to_copy = total < available ? total : available;

			memcpy(p, __FILE(stream)->buf + __FILE(stream)->buf_pos,
			       to_copy);
			__FILE(stream)->buf_pos += to_copy;
			p += to_copy;
			bytes_read += to_copy;
			total -= to_copy;
			continue;
		}

		ssize_t ret = read(__FILE(stream)->fd, __FILE(stream)->buf,
				   __FILE(stream)->buf_size);
		if (ret <= 0) {
			if (ret < 0)
				__FILE(stream)->flags |= _IO_ERR;
			else
				__FILE(stream)->flags |= _IO_EOF;
			break;
		}

		__FILE(stream)->buf_len = ret;
		__FILE(stream)->buf_pos = 0;
	}

	LIBC_UNLOCK(__FILE(stream)->lock);

	return bytes_read / size;
}
