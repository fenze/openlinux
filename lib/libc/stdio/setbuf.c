#include "stddef.h" // for NULL

#include <stdio.h> // for setvbuf, BUFSIZ, FILE, _IOFBF, _IONBF, setbuf

void setbuf(FILE *restrict stream, char *restrict buf)
{
	setvbuf(stream, buf, buf != NULL ? _IOFBF : _IONBF, BUFSIZ);
}
