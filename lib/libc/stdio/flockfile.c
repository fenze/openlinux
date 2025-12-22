#include <__stdio.h>
#include <atomic.h>
#include <stdio.h>

void flockfile(FILE *file)
{
	LIBC_LOCK(file->lock);
}
