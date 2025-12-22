#include <stdio.h>

int fileno(FILE *stream)
{
	int r;

	flockfile(stream);
	r = fileno_unlocked(stream);
	funlockfile(stream);

	return r;
}
