#include <stdarg.h> // for va_end, va_start
#include <stdio.h>  // for snprintf, vsnprintf, size_t, va_list

int snprintf(char *restrict s, size_t n, const char *restrict format, ...)
{
	int r;
	va_list ap;
	va_start(ap, format);
	r = vsnprintf(s, n, format, ap);
	va_end(ap);
	return r;
}
