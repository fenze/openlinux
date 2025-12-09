#include <stdio.h> // for fread, FILE, fgetc

int fgetc(FILE *stream)
{
	int c;

	if (fread(&c, 1, 1, stream) < 0)
		return -1;

	return c;
}
