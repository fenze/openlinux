#include <stdio.h>

size_t fread(void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream)
{
	size_t r;

	flockfile(stream);
	r = fread_unlocked(ptr, size, nitems, stream);
	funlockfile(stream);

	return r;
}
