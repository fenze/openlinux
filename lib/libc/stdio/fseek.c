#include "__stdio.h" // for _IO_EOF, _IO_ERR
#include "stddef.h"  // for NULL

#include <atomic.h> // for LIBC_LOCK, LIBC_UNLOCK
#include <libc.h>   // for __IMPL
#include <stdio.h>  // for FILE, fseek
#include <unistd.h> // for lseek, off_t

int fseek(FILE *stream, long offset, int whence)
{
	if (stream == NULL || __IMPL(stream)->fd < 0)
		return -1;

	LIBC_LOCK(__IMPL(stream)->lock);

	__IMPL(stream)->buf_pos = 0;
	__IMPL(stream)->buf_len = 0;
	__IMPL(stream)->flags &= ~_IO_EOF;

	off_t result = lseek(__IMPL(stream)->fd, offset, whence);

	LIBC_UNLOCK(__IMPL(stream)->lock);

	if (result == (off_t)-1) {
		__IMPL(stream)->flags |= _IO_ERR;
		return -1;
	}

	__IMPL(stream)->offset = result;
	return 0;
}
