#include <stdlib.h>
#include <errno.h>
#include <linux/errno.h>
#include <malloc.h>

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	size_t total = nmemb * size;
	if (nmemb != 0 && total / nmemb != size) {
		errno = ENOMEM;
		return NULL;
	}
	return realloc(ptr, total);
}
