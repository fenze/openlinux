#include <libc.h>  // for weak_reference
#include <stdio.h> // for fputc, FILE, putc, putc_unlocked

int putc(int c, FILE *stream)
{
	return fputc(c, stream);
}

weak_reference(putc, putc_unlocked);
