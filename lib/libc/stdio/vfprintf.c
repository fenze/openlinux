#include <io.h>
#include <stdio.h>

int vfprintf(FILE *restrict stream, const char *restrict format, va_list ap)
{
	return __vsnprintf(&stream->buf, stream->buf_size, format, ap);
}
