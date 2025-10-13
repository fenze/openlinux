#include <stdio.h>
#include <stdarg.h>

int printf(const char *restrict format, ...)
{
	va_list args;
	va_start(args, format);
	int ret = vfprintf(stdout, format, args);
	va_end(args);
	return ret;
}
