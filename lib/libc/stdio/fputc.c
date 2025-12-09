#include "stddef.h" // for NULL

#include <__stdio.h> // for __FILE
#include <errno.h>   // for EINVAL, errno
#include <stdio.h>   // for EOF, fwrite, FILE, fputc

int fputc(int c, FILE *stream)
{
	if (stream == NULL) {
		errno = EINVAL;
		return EOF;
	}

	if ((__FILE(stream))->fd == -1 && (__FILE(stream))->buf != NULL) {
		if ((__FILE(stream))->buf_len >=
		    (__FILE(stream))->buf_size - 1) {
			return EOF;
		}

		(__FILE(stream))->buf[(__FILE(stream))->buf_len++] = (char)c;
		return (unsigned char)c;
	}

	return fwrite(&c, 1, 1, stream) ? c : EOF;
}
