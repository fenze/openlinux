#include <math.h>
#include "__complex.h"

double complex clog10(double complex z)
{
	double p, rr;
	rr = cabs(z);
	p = log10(rr);
	rr = atan2(cimag(z), creal(z)) * M_IVLN10;
	return p + rr * (double complex)I;
}
