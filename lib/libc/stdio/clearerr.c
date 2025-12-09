#include "__stdio.h" // for __FILE, _IO_EOF, _IO_ERR
#include "stddef.h"  // for NULL

#include <stdio.h> // for FILE, clearerr

void clearerr(FILE *stream)
{
	struct __FILE *stream_impl = __FILE(stream);

	if (stream == NULL)
		return;

	stream_impl->flags &= ~(_IO_ERR | _IO_EOF);
}
