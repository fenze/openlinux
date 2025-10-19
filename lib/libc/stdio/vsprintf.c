#include <stdarg.h>
#include <stdio.h>

int vsprintf(char *restrict s, const char *restrict format, va_list ap)
{
	return vsnprintf(s, (size_t)-1, format, ap);
}
