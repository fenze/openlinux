#include <stddef.h> // for NULL
#include <string.h> // for strrchr

char *strrchr(const char *s, int c)
{
	const char *last = NULL;
	while (*s != '\0') {
		if (*s == c)
			last = s;
		s++;
	}
	return (char *)last;
}
