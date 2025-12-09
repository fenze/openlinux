#include "__stdio.h" // for _IO_ERR
#include "stddef.h"  // for NULL

#include <libc.h>  // for __IMPL
#include <stdio.h> // for FILE, ferror

int ferror(FILE *stream)
{
	if (stream == NULL)
		return 0;

	return (__IMPL(stream)->flags & _IO_ERR) != 0;
}
