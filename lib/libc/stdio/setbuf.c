#include <io.h>
#include <stdio.h>

void setbuf(FILE *restrict stream, char *restrict buf)
{
	setvbuf(stream, buf, buf != NULL ? _IOFBF : _IONBF, BUFSIZ);
}
