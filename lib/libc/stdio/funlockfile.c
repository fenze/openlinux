#include <__stdio.h>
#include <atomic.h>
#include <stdio.h>

void funlockfile(FILE *file)
{
	LIBC_UNLOCK(file->lock);
}
