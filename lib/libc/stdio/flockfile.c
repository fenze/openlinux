#include <__stdio.h>
#include <atomic.h>
#include <stdio.h>

void flockfile(FILE *file)
{
	LIBC_LOCK(((struct __FILE *)file)->lock);
}
