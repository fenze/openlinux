#include <stdint.h> // for uintmax_t
#include <stdlib.h> // for strtoull

uintmax_t strtoumax(const char *restrict s, char **restrict p, int base)
{
	return strtoull(s, p, base);
}
