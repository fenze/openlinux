#include <stdio.h>

size_t fwrite(const void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream)
{
	size_t r;

	flockfile(stream);
	r = fwrite_unlocked(ptr, size, nitems, stream);
	funlockfile(stream);

	return r;
}
