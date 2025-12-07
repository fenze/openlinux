#include <errno.h>
#include <__dirent.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>

int closedir(DIR *dirp)
{
	if (dirp->fildes >= 0) {
		errno = EBADF;
		return -1;
	}

	close(dirp->fildes);
	free(dirp);
	return 0;
}
