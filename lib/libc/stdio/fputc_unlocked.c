#include <stdio.h>

int fputc_unlocked(int c, FILE *stream)
{
	return fwrite_unlocked(&c, 1, 1, stream) ? c : EOF;
}
