#include <sys/cdefs.h>
#include <math.h>

long double nanl(const char *__unused s)
{
	return NAN;
}
