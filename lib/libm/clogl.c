#include "__complex.h"

long double complex clogl(long double complex z)
{
	long double p, rr;

	rr = cabsl(z);
	p = logl(rr);
	rr = atan2l(cimagl(z), creall(z));

	return p + rr * (long double complex)I;
}
