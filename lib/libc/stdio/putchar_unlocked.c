#include <stdio.h>

int putchar_unlocked(int c)
{
	return fputc_unlocked(c, stdout);
}
