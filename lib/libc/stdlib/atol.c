#include "stddef.h" // for NULL

#include <stdlib.h> // for strtol, atol

long atol(const char *nptr)
{
	return strtol(nptr, (char **)NULL, 10);
}
