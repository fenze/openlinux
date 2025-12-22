#include <stdio.h>

int getchar(void)
{
	int r;

	flockfile(stdin);
	r = getchar_unlocked();
	funlockfile(stdin);

	return r;
}
