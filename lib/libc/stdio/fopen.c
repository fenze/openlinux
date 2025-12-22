#include <__stdio.h>

#include <errno.h>  // for EINVAL, errno
#include <fcntl.h>  // for O_WRONLY, O_CREAT, O_RDONLY, open, O_APPEND
#include <stdio.h>  // for FILE, BUFSIZ, fopen, _IOLBF
#include <stdlib.h> // for calloc, free, malloc
#include <string.h> // for strchr
#include <sys/cdefs.h>
#include <unistd.h> // for close

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

	fd = open(pathname, flags, _mode);
	if (fd < 0)
		return NULL;

	stream = calloc(1, sizeof(struct __FILE));
	if (stream == NULL)
		return NULL;

	stream->fd = fd;
	stream->buf_size = BUFSIZ;
	stream->flags = flags;
	stream->type = _IOLBF;
	atomic_flag_clear(&stream->lock);

	stream->buf = malloc(BUFSIZ);

	if (stream->buf == NULL) {
		close(fd);
		free(stream);
		return NULL;
	}

	__libc_fadd(stream);

	return stream;
}
