#include "__complex.h"

double complex csinh(double complex z)
{
	double x, y;

	x = creal(z);
	y = cimag(z);

	return sinh(x) * cos(y) + (cosh(x) * sin(y)) * (double complex)I;
}
