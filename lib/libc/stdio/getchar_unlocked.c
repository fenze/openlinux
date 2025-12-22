#include <stdio.h>

int getchar_unlocked(void)
{
	return fgetc_unlocked(stdin);
}
