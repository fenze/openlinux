#include <math.h>
#include <complex.h>

float complex cacosf(float complex z)
{
	float complex w = casinf(z);

	return ((float)M_PI_2 - crealf(w)) - cimagf(w) * I;
}
