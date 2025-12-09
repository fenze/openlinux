#include <complex.h> // for cimagf, complex, crealf, csinhf, I
#include <math.h>    // for cosf, coshf, sinf, sinhf

float complex csinhf(float complex z)
{
	float x, y;

	x = crealf(z);
	y = cimagf(z);

	return sinhf(x) * cosf(y) + (coshf(x) * sinf(y)) * I;
}
