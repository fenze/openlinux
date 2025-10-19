#include <math.h>
#include <complex.h>

double cabs(double complex z)
{
	return hypot(creal(z), cimag(z));
}
