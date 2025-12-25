#include <stdio.h>

void clearerr(FILE *stream)
{
	flockfile(stream);
	clearerr_unlocked(stream);
	funlockfile(stream);
}
