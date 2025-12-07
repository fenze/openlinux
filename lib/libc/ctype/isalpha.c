#include <libc.h>

int isalpha(int c)
{
	return ((unsigned)c | 32) - 'a' < 26;
}

weak_reference(isalpha, isalpha_l);
