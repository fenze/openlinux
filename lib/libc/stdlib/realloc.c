#include <errno.h>
#include <string.h>
#include <atomic.h>
#include <libc.h>
#include <malloc.h>
#include <linux/errno.h>
#include <stdlib.h>

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
			} else {
				void *new_ptr = malloc(size);
				if (new_ptr) {
					memcpy(new_ptr, ptr, old_size);
					free(ptr);
				}
				return new_ptr;
			}
		}
		p = p->next;
	}

	LIBC_UNLOCK(libc.lock.malloc);

	errno = EINVAL;
	return NULL;
}
