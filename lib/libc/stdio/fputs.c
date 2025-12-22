#include <stdio.h>

int fputs(const char *restrict s, FILE *restrict stream)
{
	int r;

	flockfile(stream);
	r = fputs_unlocked(s, stream);
	funlockfile(stream);

	return r;
}
