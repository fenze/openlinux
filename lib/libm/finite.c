#define _GNU_SOURCE
#include <math.h> // for isfinite

int finite(double x)
{
	return isfinite(x);
}
