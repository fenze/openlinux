#include <stdint.h>
#include <stdlib.h>

uintmax_t strtoumax(const char *restrict s, char **restrict p, int base)
{
	return strtoull(s, p, base);
}
