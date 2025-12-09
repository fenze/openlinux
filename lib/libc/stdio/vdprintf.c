#include "__stdio.h" // for __FILE

#include <stdio.h> // for vfprintf, _IONBF, va_list, vdprintf

int vdprintf(int fildes, const char *restrict format, va_list ap)
{
	int r;
	struct __FILE stream;

	stream.fd = fildes;
	stream.type = _IONBF;

	r = vfprintf(&stream, format, ap);

	return r;
}
