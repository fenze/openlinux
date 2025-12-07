#include <libc.h>

int isblank(int c)
{
	return (c == ' ' || c == '\t');
}

weak_reference(isblank, isblank_l);
