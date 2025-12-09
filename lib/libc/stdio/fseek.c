#include "__stdio.h" // for __FILE, _IO_EOF, _IO_ERR
#include "stddef.h"  // for NULL

#include <atomic.h> // for LIBC_LOCK, LIBC_UNLOCK
#include <stdio.h>  // for FILE, fseek
#include <unistd.h> // for lseek, off_t

int fseek(FILE *stream, long offset, int whence)
{
	if (stream == NULL || __FILE(stream)->fd < 0)
		return -1;

	LIBC_LOCK(__FILE(stream)->lock);

	__FILE(stream)->buf_pos = 0;
	__FILE(stream)->buf_len = 0;
	__FILE(stream)->flags &= ~_IO_EOF;

	off_t result = lseek(__FILE(stream)->fd, offset, whence);

	LIBC_UNLOCK(__FILE(stream)->lock);

	if (result == (off_t)-1) {
		__FILE(stream)->flags |= _IO_ERR;
		return -1;
	}

	__FILE(stream)->offset = result;
	return 0;
}
