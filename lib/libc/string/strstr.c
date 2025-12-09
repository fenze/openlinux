#include <stddef.h> // for NULL
#include <string.h> // for strstr

char *strstr(const char *s1, const char *s2)
{
	const char *p = s1;
	const char *q = s2;

	if (*q == '\0')
		return (char *)p;

	while (*p != '\0') {
		const char *pp = p;
		const char *qq = q;

		while (*pp == *qq && *pp != '\0') {
			pp++;
			qq++;
		}

		if (*qq == '\0')
			return (char *)p;

		p++;
	}

	return NULL;
}
