#include <stddef.h>
#include <string.h>

size_t strspn(const char *s1, const char *s2)
{
	size_t count = 0;
	while (*s1 != '\0' && strchr(s2, *s1) != NULL) {
		count++;
		s1++;
	}
	return count;
}
