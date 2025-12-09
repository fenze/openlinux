#include <ctype.h> // for isdigit, isxdigit

int isxdigit(int c)
{
	return isdigit(c) || ((unsigned)c | 32) - 'a' < 6;
}
