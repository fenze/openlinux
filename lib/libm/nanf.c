#include <math.h>      // for nanf, NAN
#include <sys/cdefs.h> // for __unused

float nanf(const char *__unused s)
{
	return NAN;
}
