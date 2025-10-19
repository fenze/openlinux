#include <complex.h>

double complex casin(double complex z)
{
	double complex ca, ct, zz, z2;
	double x, y;

	x = creal(z);
	y = cimag(z);

	ca = x + y * I;
	ct = ca * I;

	zz = (x - y) * (x + y) + (2.0 * x * y) * I;

	zz = 1.0 - creal(zz) - cimag(zz) * I;
	z2 = csqrt(zz);

	zz = ct + z2;
	zz = clog(zz);

	return zz * (-1.0 * I);
}
