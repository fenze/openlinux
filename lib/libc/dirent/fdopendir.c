#include "stddef.h" // for NULL

#include <dirent.h>
#include <errno.h>
#include <libc/dirent.h>
#include <stdlib.h>
#include <sys/cdefs.h>

DIR *fdopendir(int fildes)
{
	struct __DIR *dir;

	if (__predict_false(fildes < 0)) {
		errno = EBADF;
		return NULL;
	}

	dir = calloc(1, sizeof(struct __DIR));
	if (__predict_false(dir == NULL)) {
		return NULL;
	}

	dir->fildes = fildes;

	return dir;
}
