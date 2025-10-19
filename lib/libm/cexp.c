#include <math.h>
#include <complex.h>

double complex cexp(double complex z)
{
	double r, x, y;

	x = creal(z);
	y = cimag(z);
	r = exp(x);

	return r * cos(y) + r * sin(y) * I;
}
