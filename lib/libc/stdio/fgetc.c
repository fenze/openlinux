#include <stdio.h>

int fgetc(FILE *stream)
{
	int r;

	flockfile(stream);
	r = fgetc_unlocked(stream);
	funlockfile(stream);

	return r;
}
