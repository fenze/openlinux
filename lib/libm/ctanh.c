#include <complex.h> // for complex, cimag, creal, ctanh, I
#include <math.h>    // for cos, cosh, sin, sinh

double complex ctanh(double complex z)
{
	double x, y, d;

	x = creal(z);
	y = cimag(z);
	d = cosh(2.0 * x) + cos(2.0 * y);

	return sinh(2.0 * x) / d + (sin(2.0 * y) / d) * (double complex)I;
}
