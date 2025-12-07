#include <errno.h>
#include <string.h>
#include <stdlib.h>

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

	if ((ptr = malloc(total)) != NULL) {
		memset(ptr, 0, total);
	}

	return ptr;
}
