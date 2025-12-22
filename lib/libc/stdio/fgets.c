#include <stdio.h>

char *fgets(char *restrict s, int n, FILE *restrict stream)
{
	char *r;

	flockfile(stream);
	r = fgets_unlocked(s, n, stream);
	funlockfile(stream);

	return r;
}
