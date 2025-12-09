#include "stddef.h" // for NULL

#include <__stdio.h> // for __FILE
#include <stdio.h>   // for _IONBF, FILE, _IOFBF, _IOLBF, setvbuf, size_t

int setvbuf(FILE *restrict stream, char *restrict buf, int type, size_t size)
{
	if (type != _IOFBF && type != _IOLBF && type != _IONBF)
		return -1;
	if (type != _IONBF && (buf == NULL || size == 0))
		return -1;

	if (__FILE(stream)->fd < 0)
		return -1;

	__FILE(stream)->buf = buf;
	__FILE(stream)->buf_size = size;
	__FILE(stream)->buf_pos = 0;
	__FILE(stream)->type = type;

	return 0;
}
