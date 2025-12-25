#include "stddef.h"
#include <__stdio.h>
#include <stdio.h>

void clearerr_unlocked(FILE *stream)
{
	if (stream != NULL)
		stream->flags &= ~(_IO_ERR | _IO_EOF);
}
