#include "stddef.h" // for NULL

#include <libc.h>  // for __IMPL
#include <stdio.h> // for _IONBF, FILE, _IOFBF, _IOLBF, setvbuf, size_t

int setvbuf(FILE *restrict stream, char *restrict buf, int type, size_t size)
{
	if (type != _IOFBF && type != _IOLBF && type != _IONBF)
		return -1;
	if (type != _IONBF && (buf == NULL || size == 0))
		return -1;

	if (__IMPL(stream)->fd < 0)
		return -1;

	__IMPL(stream)->buf = buf;
	__IMPL(stream)->buf_size = size;
	__IMPL(stream)->buf_pos = 0;
	__IMPL(stream)->type = type;

	return 0;
}
