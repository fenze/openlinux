#include "__stdio.h" // for __FILE, _IO_ERR
#include "stddef.h"  // for NULL

#include <atomic.h> // for LIBC_UNLOCK, LIBC_LOCK
#include <errno.h>  // for errno, EBADF, EIO
#include <stdio.h>

int fflush(struct __FILE *stream)
{
	int r;

	flockfile(stream);
	r = fflush_unlocked(stream);
	funlockfile(stream);

	return r;
}
