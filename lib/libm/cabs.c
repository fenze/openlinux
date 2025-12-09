#include <complex.h> // for cabs, cimag, creal, complex
#include <math.h>    // for hypot

double cabs(double complex z)
{
	return hypot(creal(z), cimag(z));
}
