#include <__stdio.h>
#include <stdio.h>

int feof_unlocked(FILE *stream)
{
	return (stream) ? stream->eof : 0;
}
