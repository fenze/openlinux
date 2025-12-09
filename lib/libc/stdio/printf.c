#include <stdarg.h> // for va_end, va_start
#include <stdio.h>  // for printf, vfprintf, stdout, va_list

int printf(const char *restrict format, ...)
{
	int r;
	va_list ap;
	va_start(ap, format);
	r = vfprintf(stdout, format, ap);
	va_end(ap);
	return r;
}
