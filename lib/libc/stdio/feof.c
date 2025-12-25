#include <stdio.h>

int feof(FILE *stream)
{
	int r;

	flockfile(stream);
	r = feof_unlocked(stream);
	funlockfile(stream);

	return r;
}
