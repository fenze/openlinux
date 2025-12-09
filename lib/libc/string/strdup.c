#include <stdlib.h> // for NULL, malloc
#include <string.h> // for memcpy, strlen, size_t, strdup

char *strdup(const char *s)
{
	size_t len = strlen(s) + 1;
	char *dup = malloc(len);
	if (dup == NULL)
		return NULL;
	memcpy(dup, s, len);
	return dup;
}
