#include "stddef.h" // for NULL

#include <errno.h>  // for EINVAL, ENOMEM
#include <stdlib.h> // for size_t, aligned_alloc, posix_memalign

int posix_memalign(void **memptr, size_t alignment, size_t size)
{
	if (memptr == NULL) {
		return EINVAL;
	}

	*memptr = NULL;

	if (alignment < sizeof(void *) || alignment % sizeof(void *) != 0 ||
	    (alignment & (alignment - 1)) != 0) {
		return EINVAL;
	}

	if (size == 0) {
		*memptr = NULL;
		return 0;
	}

	size_t aligned_size = (size + alignment - 1) & ~(alignment - 1);

	void *ptr = aligned_alloc(alignment, aligned_size);
	if (ptr == NULL) {
		return ENOMEM;
	}

	*memptr = ptr;
	return 0;
}
