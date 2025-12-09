#include <string.h> // for strcpy

char *strcpy(char *restrict s1, const char *restrict s2)
{
	char *p = s1;
	while ((*p++ = *s2++) != '\0')
		;
	return s1;
}
