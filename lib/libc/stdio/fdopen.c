#include "__stdio.h" // for __FILE, __libc_fadd
#include <stdio.h>   // for FILE, _IONBF, SEEK_END, _IOLBF, fdopen
#include <stdlib.h>  // for calloc, free
#include <sys/cdefs.h>
#include <unistd.h> // for lseek, off_t

FILE *fdopen(int fildes, const char *mode)
{
	struct __FILE *stream;

	if (mode == NULL || (mode[0] != 'r' && mode[0] != 'w' && mode[0] != 'a')) {
		return NULL;
	}

	stream = calloc(1, sizeof(struct __FILE));
	if (stream == NULL)
		return NULL;

	stream->fd = fildes;
	atomic_flag_clear(&stream->lock);

	if (mode[0] == 'r') {
		stream->type = _IONBF;
	} else if (mode[0] == 'w') {
		stream->type = _IOLBF;
	} else if (mode[0] == 'a') {
		off_t off;
		stream->type = _IONBF;
		off = lseek(fildes, 0, SEEK_END);
		if (off == (off_t)-1) {
			free(stream);
			return NULL;
		}
	}

	__libc_fadd(stream);
	return stream;
}
