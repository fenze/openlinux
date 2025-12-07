#include <stdio.h>
#include <stdarg.h>

int snprintf(char *restrict s, size_t n, const char *restrict format, ...)
{
	int r;
	va_list ap;
	va_start(ap, format);
	r = vsnprintf(s, n, format, ap);
	va_end(ap);
	return r;
}
