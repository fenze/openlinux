#include <complex.h> // for complex, cacosf, casinf, cimagf, crealf, I
#include <math.h>    // for M_PI_2

float complex cacosf(float complex z)
{
	float complex w = casinf(z);

	return ((float)M_PI_2 - crealf(w)) - cimagf(w) * I;
}
