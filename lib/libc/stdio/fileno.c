#include <atomic.h> // for LIBC_LOCK, LIBC_UNLOCK
#include <errno.h>  // for EBADF, errno
#include <libc.h>   // for __IMPL
#include <stdio.h>  // for FILE, fileno

int fileno(FILE *stream)
{
	int fd;

	LIBC_LOCK(__IMPL(stream)->lock);
	fd = __IMPL(stream)->fd;
	LIBC_UNLOCK(__IMPL(stream)->lock);

	if (fd < 0) {
		errno = EBADF;
		return -1;
	}

	return fd;
}
