/* Maintainer: <contact@bellrise.net> */

#include <__dirent.h>
#include <errno.h>
#include <dirent.h>
#include <syscall.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#include <stdio.h>

int readdir_r(DIR *restrict dirp, struct dirent *restrict entry,
	      struct dirent **restrict result)
{
	struct linux_dirent64 *ldir = (void *)dirp->buffer;
	ssize_t nread;
	int ret;

	if (dirp == NULL || entry == NULL || result == NULL) {
		return EINVAL;
	}

	if (dirp->cached) {
		ldir = (void *)(dirp->buffer + dirp->offset);
		entry->d_ino = ldir->d_ino;
		strcpy(entry->d_name, ldir->d_name);
		dirp->cached--;
		dirp->offset += ldir->d_reclen;
		*result = entry;
		return 0;
	}

	ret = syscall(getdents64, dirp->fildes, dirp->buffer,
		      sizeof(dirp->buffer));
	if (ret < 0)
		return errno;

	if (ret == 0) {
		*result = NULL;
		return 0;
	}

	/* Read first entry from buffer. */
	nread = ret;
	dirp->offset = ldir->d_reclen;
	entry->d_ino = ldir->d_ino;
	strcpy(entry->d_name, ldir->d_name);
	*result = entry;

	/* Count the amount of remaining entries we have cached from getdents.  */
	for (ssize_t buffer_offset = ldir->d_reclen; buffer_offset < nread;) {
		ldir = (void *)(dirp->buffer + buffer_offset);
		buffer_offset += ldir->d_reclen;
		dirp->cached++;
	}

	return 0;
}
