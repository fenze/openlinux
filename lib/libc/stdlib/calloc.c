#include <errno.h>
#include <string.h>
#include <stdlib.h>

void *calloc(size_t nelem, size_t elsize)
{
	size_t total = nelem * elsize;
	if (nelem != 0 && total / nelem != elsize) {
		errno = ENOMEM;
		return NULL;
	}

	void *ptr = malloc(total);
	if (ptr) {
		memset(ptr, 0, total);
	}
	return ptr;
}
