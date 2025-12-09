#include <libc.h>  // for weak_reference
#include <stdio.h> // for fgetc, FILE, getc, getc_unlocked

int getc(FILE *stream)
{
	return fgetc(stream);
}

weak_reference(getc, getc_unlocked);
