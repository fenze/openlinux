#include <libc.h>  // for weak_reference
#include <stdio.h> // for fgetc, getchar, getchar_unlocked, stdin

int getchar(void)
{
	return fgetc(stdin);
}

weak_reference(getchar, getchar_unlocked);
