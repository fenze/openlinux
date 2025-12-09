#include <stdarg.h> // for va_end, va_start
#include <stdio.h>  // for fprintf, vfprintf, FILE, va_list

int fprintf(FILE *restrict stream, const char *restrict format, ...)
{
	int r;
	va_list ap;
	va_start(ap, format);
	r = vfprintf(stream, format, ap);
	va_end(ap);
	return r;
}
