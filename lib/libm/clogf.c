#include "__complex.h"

float complex clogf(float complex z)
{
	float p, rr;

	rr = cabsf(z);
	p = logf(rr);
	rr = atan2f(cimagf(z), crealf(z));

	return p + rr * I;
}
