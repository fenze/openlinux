#include <errno.h>
#include <__dirent.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

DIR *fdopendir(int fildes)
{
	DIR *dir;

	if (fildes < 0) {
		errno = EBADF;
		return NULL;
	}

	if ((dir = calloc(1, sizeof(DIR))) == NULL) {
		return NULL;
	}

	dir->fildes = fildes;

	return dir;
}
