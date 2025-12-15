#include "__stdio.h" // for __FILE, __libc_fadd
#include "stddef.h"  // for NULL

#include <errno.h>  // for EINVAL, errno
#include <fcntl.h>  // for O_WRONLY, O_CREAT, O_RDONLY, O_APPEND, O_RDWR
#include <stdio.h>  // for FILE, _IOFBF, fmemopen, size_t
#include <stdlib.h> // for calloc, free
#include <string.h> // for strchr

#include <sys/cdefs.h>

__weak void __stdio_cleanup(void)
{
}

FILE *fmemopen(void *restrict buf, size_t max_size, const char *restrict mode)
{
	int flags;
	FILE *stream = calloc(1, sizeof(FILE));

	if (stream == NULL)
		return stream;

	__FILE(stream)->fd = -1;
	__FILE(stream)->buf = buf;
	__FILE(stream)->buf_size = max_size;
	__FILE(stream)->type = _IOFBF;

	if (mode[0] == 'r') {
		flags = O_RDONLY;
	} else if (mode[0] == 'w') {
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	} else if (mode[0] == 'a') {
		flags = O_WRONLY | O_CREAT | O_APPEND;
	} else {
		free(stream);
		errno = EINVAL;
		return NULL;
	}

	if (strchr(mode, '+')) {
		flags = (flags & ~(O_RDONLY | O_WRONLY)) | O_RDWR;
	}

	__FILE(stream)->flags = flags;

	__libc_fadd(stream);

	return stream;
}
