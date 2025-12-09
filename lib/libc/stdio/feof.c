#include "stddef.h" // for NULL

#include <libc.h>  // for __IMPL
#include <stdio.h> // for FILE, feof

int feof(FILE *stream)
{
	if (stream == NULL)
		return 0;

	return __IMPL(stream)->eof;
}
