#include <math.h>
#include <complex.h>

float complex cexpf(float complex z)
{
	float r, x, y;

	x = crealf(z);
	y = cimagf(z);
	r = expf(x);

	return r * cosf(y) + r * sinf(y) * I;
}
