#include <string.h> // for size_t, strchr, strspn, NULL

size_t strspn(const char *s1, const char *s2)
{
	size_t count = 0;
	while (*s1 != '\0' && strchr(s2, *s1) != NULL) {
		count++;
		s1++;
	}
	return count;
}
