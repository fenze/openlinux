#include "__stdio.h" // for __FILE, _IO_ERR

#include <stdio.h>

int fflush(struct __FILE *stream)
{
	int r;

	flockfile(stream);
	r = fflush_unlocked(stream);
	funlockfile(stream);

	return r;
}
