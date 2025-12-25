#include <__stdio.h>
#include <atomic.h>
#include <stdio.h>

void funlockfile(struct __FILE *file)
{
	LIBC_UNLOCK(file->lock);
}
