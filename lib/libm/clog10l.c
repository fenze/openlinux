#include <complex.h> // for complex, cabsl, cimagl, creall, I
#include <math.h>    // for atan2l, log10l

long double complex clog10l(long double complex z)
{
	long double p, rr;
	rr = cabsl(z);
	p = log10l(rr);
	rr = atan2l(cimagl(z), creall(z)) *
	     0.43429448190325182765112891891660508229439700580366656611445378316586464920887L;
	return p + rr * (long double complex)I;
}
