#include <stdio.h>

int ferror(FILE *stream)
{
	int r;

	flockfile(stream);
	r = ferror_unlocked(stream);
	funlockfile(stream);

	return r;
}
