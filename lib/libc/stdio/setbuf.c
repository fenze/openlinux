#include <stdio.h> // for setvbuf, BUFSIZ, FILE, NULL, _IOFBF, _IONBF, setbuf

void setbuf(FILE *restrict stream, char *restrict buf)
{
	setvbuf(stream, buf, buf != NULL ? _IOFBF : _IONBF, BUFSIZ);
}
