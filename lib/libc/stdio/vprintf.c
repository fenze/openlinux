#include <stdio.h> // for vfprintf, vprintf, stdout, va_list

int vprintf(const char *restrict format, va_list ap)
{
	return vfprintf(stdout, format, ap);
}
