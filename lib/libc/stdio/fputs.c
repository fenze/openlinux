#include <stdio.h>  // for fwrite, EOF, FILE, fputs
#include <string.h> // for strlen

int fputs(const char *restrict s, FILE *restrict stream)
{
	return fwrite(s, 1, strlen(s), stream) == strlen(s) ? 0 : EOF;
}
