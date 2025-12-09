#include <math.h>
#include <complex.h>

float complex ccoshf(float complex z)
{
	float x, y;

	x = crealf(z);
	y = cimagf(z);

	return coshf(x) * cosf(y) + (sinhf(x) * sinf(y)) * I;
}
