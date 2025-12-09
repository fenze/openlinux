#include <complex.h> // for ccosh, cimag, complex, creal, I
#include <math.h>    // for cos, cosh, sin, sinh

double complex ccosh(double complex z)
{
	double x, y;

	x = creal(z);
	y = cimag(z);

	return cosh(x) * cos(y) + (sinh(x) * sin(y)) * I;
}
