#include <complex.h> // for cimagf, complex, crealf, ctanhf, I
#include <math.h>    // for cosf, coshf, sinf, sinhf

float complex ctanhf(float complex z)
{
	float x, y, d;

	x = crealf(z);
	y = cimagf(z);
	d = coshf(2.0f * x) + cosf(2.0f * y);

	return sinhf(2.0f * x) / d + (sinf(2.0f * y) / d) * I;
}
