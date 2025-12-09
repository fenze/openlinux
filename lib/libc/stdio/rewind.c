#include <stdio.h> // for clearerr, fseek, FILE, SEEK_SET, rewind

void rewind(FILE *stream)
{
	fseek(stream, 0L, SEEK_SET);
	clearerr(stream);
}
