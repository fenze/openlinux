#include "__stdio.h"   // for __FILE, __libc_fadd
#include "features.h"  // for __weak
#include "stdatomic.h" // for atomic_flag_clear
#include "stddef.h"    // for NULL

#include <stdio.h>  // for FILE, _IONBF, SEEK_END, _IOLBF, fdopen
#include <stdlib.h> // for calloc, free
#include <unistd.h> // for lseek, off_t

__weak void __stdio_cleanup(void)
{
}

FILE *fdopen(int fildes, const char *mode)
{
	FILE *stream;

	if (mode == NULL ||
	    (mode[0] != 'r' && mode[0] != 'w' && mode[0] != 'a')) {
		return NULL;
	}

	stream = calloc(1, sizeof(FILE));
	if (stream == NULL)
		return NULL;

	__FILE(stream)->fd = fildes;
	atomic_flag_clear(&__FILE(stream)->lock);
	if (mode[0] == 'r') {
		__FILE(stream)->type = _IONBF;
	} else if (mode[0] == 'w') {
		__FILE(stream)->type = _IOLBF;
	} else if (mode[0] == 'a') {
		__FILE(stream)->type = _IONBF;

		off_t offset = lseek(fildes, 0, SEEK_END);
		if (offset == (off_t)-1) {
			free(stream);
			return NULL;
		}
	}

	__libc_fadd(stream);
	return stream;
}
