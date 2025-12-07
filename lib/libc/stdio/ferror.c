#include <stdio.h>
#include <io.h>

int ferror(FILE *stream)
{
	if (!stream)
		return 0;

	return (stream->flags & _IO_ERR) != 0;
}
