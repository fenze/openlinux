#include <stddef.h>

int strcmp(const char *s1, const char *s2)
{
	const unsigned char *p1 = (const unsigned char *)s1;
	const unsigned char *p2 = (const unsigned char *)s2;

	if (p1 == NULL && p2 == NULL)
		return 0;

	if (p1 == NULL)
		return -1;

	if (p2 == NULL)
		return 1;

	while (*p1 == *p2 && *p1 != '\0') {
		p1++;
		p2++;
	}

	return *p1 - *p2;
}
