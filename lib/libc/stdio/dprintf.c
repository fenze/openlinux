#include <stdarg.h> // for va_end, va_start
#include <stdio.h>  // for vdprintf, dprintf, va_list

int dprintf(int fildes, const char *restrict format, ...)
{
	int r;
	va_list ap;
	va_start(ap, format);
	r = vdprintf(fildes, format, ap);
	va_end(ap);
	return r;
}
