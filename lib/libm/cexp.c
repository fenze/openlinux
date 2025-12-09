#include <complex.h> // for cexp, cimag, complex, creal, I
#include <math.h>    // for cos, exp, sin

double complex cexp(double complex z)
{
	double r, x, y;

	x = creal(z);
	y = cimag(z);
	r = exp(x);

	return r * cos(y) + r * sin(y) * I;
}
