#define _GNU_SOURCE
#include <math.h> // for ilogb, scalbn

double significand(double x)
{
	return scalbn(x, -ilogb(x));
}
