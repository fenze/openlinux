#include "__complex.h" // for M_IVLN10

#include <complex.h> // for cabsf, cimagf, complex, crealf, I
#include <math.h>    // for atan2f, log10f

float complex clog10f(float complex z)
{
	float p, rr;

	rr = cabsf(z);
	p = log10f(rr);
	rr = atan2f(cimagf(z), crealf(z)) * (float)M_IVLN10;

	return p + rr * I;
}
