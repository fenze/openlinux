#include <io.h>
#include <stdio.h>

int fprintf(FILE *restrict stream, const char *restrict format, ...)
{
	va_list args;
	va_start(args, format);
	int ret = __vsnprintf(&stream->buf, stream->buf_size, format, args);
	va_end(args);
	return ret;
}
