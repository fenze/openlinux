#include <math.h>
#include <complex.h>

double complex ccosh(double complex z)
{
	double x, y;

	x = creal(z);
	y = cimag(z);

	return cosh(x) * cos(y) + (sinh(x) * sin(y)) * I;
}
