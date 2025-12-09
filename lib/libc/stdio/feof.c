#include "stddef.h" // for NULL

#include <__stdio.h> // for __FILE
#include <stdio.h>   // for FILE, feof

int feof(FILE *stream)
{
	if (stream == NULL)
		return 0;

	return (__FILE(stream))->eof;
}
