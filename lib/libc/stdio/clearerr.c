#include "__stdio.h" // for _IO_EOF, _IO_ERR
#include "stddef.h"  // for NULL

#include <libc.h>  // for __IMPL
#include <stdio.h> // for FILE, clearerr

void clearerr(FILE *stream)
{
	if (stream == NULL)
		return;

	__IMPL(stream)->flags &= ~(_IO_ERR | _IO_EOF);
}
