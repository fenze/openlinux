#include <io.h>
#include <stdio.h>

int setvbuf(FILE *restrict stream, char *restrict buf, int type, size_t size)
{
	if (type != _IOFBF && type != _IOLBF && type != _IONBF)
		return -1;
	if (type != _IONBF && (buf == NULL || size == 0))
		return -1;

	if (stream->fd < 0)
		return -1;

	stream->buf = buf;
	stream->buf_size = size;
	stream->buf_pos = 0;
	stream->type = type;

	return 0;
}
