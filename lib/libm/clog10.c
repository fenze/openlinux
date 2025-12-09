#include "__complex.h" // for M_IVLN10

#include <complex.h> // for complex, cabs, cimag, creal, I
#include <math.h>    // for atan2, log10

double complex clog10(double complex z)
{
	double p, rr;
	rr = cabs(z);
	p = log10(rr);
	rr = atan2(cimag(z), creal(z)) * M_IVLN10;
	return p + rr * (double complex)I;
}
