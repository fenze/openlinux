#include <stdio.h>
#include <string.h>

int fputs_unlocked(const char *s, FILE *stream)
{
	size_t len = strlen(s);

	return fwrite_unlocked(s, 1, len, stream) == len ? 0 : EOF;
}
