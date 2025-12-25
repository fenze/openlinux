#include "stddef.h" // for NULL

#include <errno.h>  // for errno, EINVAL, ENOMEM
#include <stdint.h> // for uintptr_t
#include <stdlib.h> // for size_t, aligned_alloc, malloc

void *aligned_alloc(size_t alignment, size_t size)
{
	if (alignment == 0 || (alignment & (alignment - 1)) != 0) {
		errno = EINVAL;
		return NULL;
	}

	if (size % alignment != 0) {
		errno = EINVAL;
		return NULL;
	}

	if (size == 0) {
		return NULL;
	}

	size_t total_size = size + alignment - 1 + sizeof(void *);

	void *raw_ptr = malloc(total_size);
	if (raw_ptr == NULL) {
		errno = ENOMEM;
		return NULL;
	}

	uintptr_t raw_addr = (uintptr_t)raw_ptr;
	uintptr_t aligned_addr = (raw_addr + sizeof(void *) + alignment - 1) & ~(alignment - 1);

	void **orig_ptr_slot = (void **)(aligned_addr - sizeof(void *));
	*orig_ptr_slot = raw_ptr;

	return (void *)aligned_addr;
}
