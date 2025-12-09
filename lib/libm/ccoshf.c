#include <complex.h> // for ccoshf, cimagf, complex, crealf, I
#include <math.h>    // for cosf, coshf, sinf, sinhf

float complex ccoshf(float complex z)
{
	float x, y;

	x = crealf(z);
	y = cimagf(z);

	return coshf(x) * cosf(y) + (sinhf(x) * sinf(y)) * I;
}
