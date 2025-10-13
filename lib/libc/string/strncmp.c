#include <stddef.h>

int strncmp(const char *s1, const char *s2, size_t n)
{
	int result = 0;

	while (n > 0 && *s1 != '\0' && *s2 != '\0') {
		if ((result = *s1 - *s2) != 0)
			break;
		s1++;
		s2++;
		n--;
	}

	if (n == 0)
		result = 0;

	return result;
}
