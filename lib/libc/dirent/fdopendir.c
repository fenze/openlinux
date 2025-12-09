#include "stddef.h" // for NULL

#include <__dirent.h> // for __DIR
#include <dirent.h>   // for DIR, fdopendir
#include <errno.h>    // for EBADF, errno
#include <stdlib.h>   // for calloc

DIR *fdopendir(int fildes)
{
	struct __DIR *dir;

	if (fildes < 0) {
		errno = EBADF;
		return NULL;
	}

	if ((dir = calloc(1, sizeof(struct __DIR))) == NULL) {
		return NULL;
	}

	dir->fildes = fildes;

	return dir;
}
