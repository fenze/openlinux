#include "stddef.h"
#include <errno.h>  // for errno, EINVAL, ENOMEM
#include <stdlib.h> // for calloc, malloc
#include <string.h> // for size_t, memset

void *calloc(size_t nelem, size_t elsize)
{
	void *ptr;
	size_t total;

	if (nelem == 0 || elsize == 0) {
		errno = EINVAL;
		return NULL;
	}

	if (__builtin_mul_overflow(nelem, elsize, &total)) {
		errno = ENOMEM;
		return NULL;
	}

	ptr = malloc(total);
	if (ptr != NULL) {
		memset(ptr, 0, total);
	}

	return ptr;
}
