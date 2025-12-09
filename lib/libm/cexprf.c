#include <complex.h> // for cexpf, cimagf, complex, crealf, I
#include <math.h>    // for cosf, expf, sinf

float complex cexpf(float complex z)
{
	float r, x, y;

	x = crealf(z);
	y = cimagf(z);
	r = expf(x);

	return r * cosf(y) + r * sinf(y) * I;
}
