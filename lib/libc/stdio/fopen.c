#include "__stdio.h"   // for __FILE, __libc_fadd
#include "features.h"  // for __weak
#include "stdatomic.h" // for atomic_flag_clear
#include "stddef.h"    // for NULL

#include <errno.h>  // for EINVAL, errno
#include <fcntl.h>  // for O_WRONLY, O_CREAT, O_RDONLY, open, O_APPEND
#include <stdio.h>  // for FILE, BUFSIZ, fopen, _IOLBF
#include <stdlib.h> // for calloc, free, malloc
#include <string.h> // for strchr
#include <unistd.h> // for close

__weak void __stdio_cleanup(void)
{
}

FILE *fopen(const char *restrict pathname, const char *restrict mode)
{
	int fd, flags, _mode;
	FILE *stream;

	_mode = 0;
	if (mode[0] == 'r') {
		flags = O_RDONLY;
	} else if (mode[0] == 'w') {
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	} else if (mode[0] == 'a') {
		flags = O_WRONLY | O_CREAT | O_APPEND;
		_mode = 0666;
	} else {
		errno = EINVAL;
		return NULL;
	}

	if (strchr(mode, '+')) {
		flags = (flags & ~(O_RDONLY | O_WRONLY)) | O_RDWR;
	}

	if ((fd = open(pathname, flags, _mode)) < 0)
		return NULL;

	if ((stream = calloc(1, sizeof(FILE))) == NULL)
		return NULL;

	__FILE(stream)->fd = fd;
	__FILE(stream)->buf_size = BUFSIZ;
	__FILE(stream)->flags = flags;
	__FILE(stream)->type = _IOLBF;
	atomic_flag_clear(&__FILE(stream)->lock);

	if ((__FILE(stream)->buf = malloc(BUFSIZ)) == NULL) {
		close(fd);
		free(stream);
		return NULL;
	}

	__libc_fadd(stream);

	return stream;
}
