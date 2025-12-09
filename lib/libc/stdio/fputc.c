#include "stddef.h" // for NULL

#include <errno.h> // for EINVAL, errno
#include <libc.h>  // for __IMPL
#include <stdio.h> // for EOF, fwrite, FILE, fputc

int fputc(int c, FILE *stream)
{
	if (stream == NULL) {
		errno = EINVAL;
		return EOF;
	}

	if (__IMPL(stream)->fd == -1 && __IMPL(stream)->buf != NULL) {
		if (__IMPL(stream)->buf_len >= __IMPL(stream)->buf_size - 1) {
			return EOF;
		}

		__IMPL(stream)->buf[__IMPL(stream)->buf_len++] = (char)c;
		return (unsigned char)c;
	}

	return fwrite(&c, 1, 1, stream) ? c : EOF;
}
