#include <math.h>      // for nanl, NAN
#include <sys/cdefs.h> // for __unused

long double nanl(const char *__unused s)
{
	return NAN;
}
