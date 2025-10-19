#include <math.h>
#include <complex.h>

float cabsf(float complex z)
{
	return hypotf(crealf(z), cimagf(z));
}
