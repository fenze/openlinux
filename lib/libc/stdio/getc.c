#include <stdio.h>

int getc(FILE *stream)
{
	int r;

	flockfile(stream);
	r = getc_unlocked(stream);
	funlockfile(stream);

	return r;
}
