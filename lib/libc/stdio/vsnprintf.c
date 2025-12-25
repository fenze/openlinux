#include "__stdio.h" // for __FILE
#include "stddef.h"  // for NULL

#include <fcntl.h>     // for O_WRONLY
#include <stdatomic.h> // for atomic_flag_clear
#include <stdio.h>     // for vfprintf, vsnprintf, _IONBF, size_t, va_list
#include <string.h>    // for memset

int vsnprintf(char *restrict s, size_t n, const char *restrict format, va_list ap)
{
	int r;
	struct __FILE stream;

	if (n == 0) {
		return 0;
	}

	if (s == NULL) {
		return -1;
	}

	memset(&stream, 0, sizeof(stream));
	stream.fd = -1;
	stream.flags = O_WRONLY;
	stream.type = _IONBF;
	atomic_flag_clear(&stream.lock);
	stream.buf = s;
	stream.buf_size = n;
	stream.buf_len = 0;
	stream.buf_pos = 0;
	stream.eof = 0;
	stream.unget_cnt = 0;
	stream.offset = 0;
	stream.next = NULL;

	r = vfprintf(&stream, format, ap);

	if (stream.buf_len < n) {
		s[stream.buf_len] = '\0';
	} else if (n > 0) {
		s[n - 1] = '\0';
		r = n - 1;
	}

	return r;
}
