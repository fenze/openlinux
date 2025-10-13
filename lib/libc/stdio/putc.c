#include <stdio.h>

int putc(int c, FILE *stream)
{
	return fputc(c, stream);
}
