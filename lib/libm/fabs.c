#include <math.h>   // for fabs
#include <stdint.h> // for uint64_t

double fabs(double x)
{
	union {
		double f;
		uint64_t i;
	} u = { x };
	u.i &= -1ULL / 2;
	return u.f;
}
