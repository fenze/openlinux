#include <stdarg.h> // for va_end, va_start
#include <stdio.h>  // for sprintf, vsprintf, va_list

int sprintf(char *restrict s, const char *restrict format, ...)
{
	int r;
	va_list ap;
	va_start(ap, format);
	r = vsprintf(s, format, ap);
	va_end(ap);
	return r;
}
