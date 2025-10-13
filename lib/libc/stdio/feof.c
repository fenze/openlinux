#include <stdio.h>
#include <io.h>

int feof(FILE *stream)
{
	if (!stream)
		return 0;

	return (stream->flags & _IO_EOF) != 0;
}
