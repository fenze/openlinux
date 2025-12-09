#include <sys/cdefs.h>
#include <math.h>

float nanf(const char *__unused s)
{
	return NAN;
}
