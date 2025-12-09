#include <complex.h> // for complex, cabsl, cimagl, clogl, creall, I
#include <math.h>    // for atan2l, logl

long double complex clogl(long double complex z)
{
	long double p, rr;

	rr = cabsl(z);
	p = logl(rr);
	rr = atan2l(cimagl(z), creall(z));

	return p + rr * (long double complex)I;
}
