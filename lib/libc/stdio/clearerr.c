#include <stdio.h>
#include <io.h>

void clearerr(FILE *stream)
{
	if (stream == NULL)
		return;

	stream->flags &= ~(_IO_ERR | _IO_EOF);
}
