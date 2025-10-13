#include <libc.h>
#include <sys/mman.h>
#include <atomic.h>
#include <malloc.h>

void free(void *ptr)
{
	if (ptr == NULL) {
		return;
	}

	LIBC_LOCK(libc.lock.malloc);

	struct page *p = page_list;
	while (p) {
		if ((uintptr_t)ptr >= (uintptr_t)p->heap &&
		    (uintptr_t)ptr < (uintptr_t)(p->heap + (p->block.size *
							    p->block.count))) {
			size_t offset = (uintptr_t)ptr - (uintptr_t)p->heap;
			size_t index = offset / p->block.size;
			size_t byte_index = index / 8;
			size_t bit_index = index % 8;

			LIBC_LOCK(p->lock);
			if (p->bitmap[byte_index] & (1 << bit_index)) {
				p->bitmap[byte_index] &= ~(1 << bit_index);
				p->block.used--;
			}
			LIBC_UNLOCK(p->lock);

			if (p->block.used == 0) {
				if (p->prev)
					p->prev->next = p->next;
				if (p->next)
					p->next->prev = p->prev;
				if (p == page_list)
					page_list = p->next;

				munmap(p, (p->flags == PAGE_SMALL) ?
						  SMALL_PAGE_SIZE :
					  (p->flags == PAGE_MEDIUM) ?
						  MEDIUM_PAGE_SIZE :
						  LARGE_PAGE_SIZE);
			}

			LIBC_UNLOCK(libc.lock.malloc);
			return;
		}
		p = p->next;
	}

	LIBC_UNLOCK(libc.lock.malloc);
}
