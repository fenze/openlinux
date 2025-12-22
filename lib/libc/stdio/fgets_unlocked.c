#include <stdio.h>

char *fgets_unlocked(char *s, int n, FILE *stream)
{
	return fread_unlocked(s, 1, n, stream) ? s : NULL;
}
