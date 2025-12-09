#include <stdarg.h> // for va_end, va_start
#include <stdio.h>  // for vasprintf, asprintf, va_list

int asprintf(char **restrict ptr, const char *restrict format, ...)
{
	int r;
	va_list ap;
	va_start(ap, format);
	r = vasprintf(ptr, format, ap);
	va_end(ap);
	return r;
}
