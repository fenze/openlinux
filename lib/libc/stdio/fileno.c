#include <__stdio.h> // for __FILE
#include <atomic.h>  // for LIBC_LOCK, LIBC_UNLOCK
#include <errno.h>   // for EBADF, errno
#include <stdio.h>   // for FILE, fileno

int fileno(FILE *stream)
{
	int fd;

	LIBC_LOCK(__FILE(stream)->lock);
	fd = __FILE(stream)->fd;
	LIBC_UNLOCK(__FILE(stream)->lock);

	if (fd < 0) {
		errno = EBADF;
		return -1;
	}

	return fd;
}
