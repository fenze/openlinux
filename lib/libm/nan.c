#include <math.h>      // for nan, NAN
#include <sys/cdefs.h> // for __unused

double nan(const char *__unused s)
{
	return NAN;
}
