#include <stddef.h> // for NULL
#include <string.h> // for size_t, strlen

size_t strlen(const char *str)
{
	size_t len = 0;

	if (str == NULL)
		return 0;

	while (*str++)
		len++;

	return len;
}
