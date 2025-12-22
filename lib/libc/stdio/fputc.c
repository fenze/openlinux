#include <stdio.h>

int fputc(int c, FILE *stream)
{
	int r;

	flockfile(stream);
	r = fputc_unlocked(c, stream);
	funlockfile(stream);

	return r;
}
