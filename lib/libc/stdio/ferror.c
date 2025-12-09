#include "__stdio.h" // for __FILE, _IO_ERR
#include "stddef.h"  // for NULL

#include <stdio.h> // for FILE, ferror

int ferror(FILE *stream)
{
	if (stream == NULL)
		return 0;

	return (__FILE(stream)->flags & _IO_ERR) != 0;
}
