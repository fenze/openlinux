#include "stddef.h" // for NULL

#include <errno.h>  // for ENOMEM, errno
#include <stdlib.h> // for size_t, realloc, reallocarray

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	size_t total = nmemb * size;
	if (nmemb != 0 && total / nmemb != size) {
		errno = ENOMEM;
		return NULL;
	}
	return realloc(ptr, total);
}
