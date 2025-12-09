#include "stddef.h" // for NULL

#include <stdlib.h> // for strtoll, atoll

long long atoll(const char *nptr)
{
	return strtoll(nptr, (char **)NULL, 10);
}
