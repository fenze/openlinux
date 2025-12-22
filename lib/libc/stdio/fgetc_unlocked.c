#include <stdio.h>

int fgetc_unlocked(FILE *stream)
{
	int c;

	if (fread_unlocked(&c, 1, 1, stream) < 0)
		return -1;

	return c;
}
