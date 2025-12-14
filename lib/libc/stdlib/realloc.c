#include "stddef.h" // for NULL

#include <atomic.h> // for LIBC_UNLOCK, LIBC_LOCK
#include <errno.h>  // for EINVAL, errno
#include <libc.h>   // for libc, libc::(anonymous)
#include <malloc.h> // for page, page::(anonymous), __malloc_pvec
#include <stdint.h> // for uintptr_t
#include <stdlib.h> // for free, malloc, realloc
#include <string.h> // for memcpy, size_t

void *realloc(void *ptr, size_t size)
{
	if (ptr == NULL) {
		return malloc(size);
	}
	if (size == 0) {
		free(ptr);
		return NULL;
	}

	LIBC_LOCK(libc.lock.malloc);

	struct page *p = __malloc_pvec;
	while (p) {
		if ((uintptr_t)ptr >= (uintptr_t)p->heap &&
		    (uintptr_t)ptr < (uintptr_t)(p->heap + (p->block.size *
							    p->block.count))) {
			size_t old_size = p->block.size;
			LIBC_UNLOCK(libc.lock.malloc);

			if (size <= old_size) {
				return ptr;
			}
			void *new_ptr = malloc(size);
			if (new_ptr) {
				memcpy(new_ptr, ptr, old_size);
				free(ptr);
			}
			return new_ptr;
		}
		p = p->next;
	}

	LIBC_UNLOCK(libc.lock.malloc);

	errno = EINVAL;
	return NULL;
}
