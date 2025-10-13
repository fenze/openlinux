#include <stdio.h>
#include <string.h>

int fputs(const char *restrict s, FILE *restrict stream)
{
	return fwrite(s, 1, strlen(s), stream) == strlen(s) ? 0 : EOF;
}
