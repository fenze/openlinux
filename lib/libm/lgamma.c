#include "libm.h" // for __lgamma_r, __signgam

#include <math.h> // for lgamma

double lgamma(double x)
{
	return __lgamma_r(x, &__signgam);
}
