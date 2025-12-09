#include <complex.h> // for cabsf, cimagf, clogf, complex, crealf, I
#include <math.h>    // for atan2f, logf

float complex clogf(float complex z)
{
	float p, rr;

	rr = cabsf(z);
	p = logf(rr);
	rr = atan2f(cimagf(z), crealf(z));

	return p + rr * I;
}
