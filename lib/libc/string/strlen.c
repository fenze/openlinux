#include <stddef.h>

size_t strlen(const char *str)
{
	size_t len = 0;

	if (str == NULL)
		return 0;

	while (*str++)
		len++;

	return len;
}
