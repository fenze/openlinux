#include <stddef.h>

char *strpbrk(const char *s1, const char *s2)
{
	while (*s1 != '\0') {
		const char *p = s2;
		while (*p != '\0') {
			if (*s1 == *p)
				return (char *)s1;
			p++;
		}
		s1++;
	}

	return NULL;
}
