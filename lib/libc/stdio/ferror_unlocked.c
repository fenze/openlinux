#include <__stdio.h>
#include <stdio.h>

int ferror_unlocked(FILE *stream)
{
	return (stream) ? (stream->flags & _IO_ERR) != 0 : 0;
}
