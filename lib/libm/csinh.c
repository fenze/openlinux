#include <complex.h> // for complex, cimag, creal, csinh, I
#include <math.h>    // for cos, cosh, sin, sinh

double complex csinh(double complex z)
{
	double x, y;

	x = creal(z);
	y = cimag(z);

	return sinh(x) * cos(y) + (cosh(x) * sin(y)) * (double complex)I;
}
