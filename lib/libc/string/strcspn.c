#include <string.h> // for size_t, strchr, strcspn, NULL

size_t strcspn(const char *s1, const char *s2)
{
	size_t len = 0;
	while (*s1 != '\0' && strchr(s2, *s1) == NULL) {
		s1++;
		len++;
	}
	return len;
}
