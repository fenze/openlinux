#include <stdio.h> // for vsnprintf, vsprintf, size_t, va_list

int vsprintf(char *restrict s, const char *restrict format, va_list ap)
{
	return vsnprintf(s, (size_t)-1, format, ap);
}
