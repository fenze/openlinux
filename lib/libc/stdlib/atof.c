#include "stddef.h" // for NULL

#include <stdlib.h> // for strtod, atof

double atof(const char *str)
{
	return strtod(str, (char **)NULL);
}
