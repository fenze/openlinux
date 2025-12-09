#include <complex.h> // for complex, cabs, cimag, clog, creal, I
#include <math.h>    // for atan2, log

double complex clog(double complex z)
{
	double p, rr;
	rr = cabs(z);
	p = log(rr);
	rr = atan2(cimag(z), creal(z));
	return p + rr * (double complex)I;
}
