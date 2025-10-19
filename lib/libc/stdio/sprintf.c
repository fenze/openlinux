#include <stdio.h>
#include <limits.h>
#include <stdarg.h>

int sprintf(char *restrict s, const char *restrict format, ...)
{
	int r;
	va_list ap;
	va_start(ap, format);
	r = vsprintf(s, format, ap);
	va_end(ap);
	return r;
}
