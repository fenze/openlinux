#include <__dirent.h> // for __DIR
#include <dirent.h>   // for DIR, closedir
#include <errno.h>    // for EBADF, errno
#include <stdlib.h>   // for free
#include <unistd.h>   // for close

int closedir(DIR *dirp)
{
	struct __DIR *rdirp = (struct __DIR *)dirp;

	if (rdirp->fildes >= 0) {
		errno = EBADF;
		return -1;
	}

	close(rdirp->fildes);
	free(rdirp);
	return 0;
}
