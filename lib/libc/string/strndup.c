#include <stdlib.h> // for NULL, malloc
#include <string.h> // for memcpy, size_t, strndup

char *strndup(const char *s, size_t size)
{
	char *result = malloc(size + 1);

	if (result == NULL)
		return NULL;

	memcpy(result, s, size);
	result[size] = '\0';

	return result;
}
