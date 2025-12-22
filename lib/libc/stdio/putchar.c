#include <stdio.h>

int putchar(int c)
{
	int r;

	flockfile(stdout);
	r = putchar_unlocked(c);
	funlockfile(stdout);

	return r;
}
