#include <stdlib.h>
#include <string.h>

char *strdup(const char *s)
{
	size_t len = strlen(s) + 1;
	char *dup = malloc(len);
	if (dup == NULL)
		return NULL;
	memcpy(dup, s, len);
	return dup;
}
