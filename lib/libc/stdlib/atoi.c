#include "stddef.h" // for NULL

#include <stdlib.h> // for strtol, atoi

int atoi(const char *str)
{
	return (int)strtol(str, (char **)NULL, 10);
}
