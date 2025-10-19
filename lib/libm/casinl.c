#include <complex.h>

long double complex casinl(long double complex z)
{
	long double complex ca, ct, zz, z2;
	long double x, y;

	x = creall(z);
	y = cimagl(z);
	ca = x + y * I;
	ct = ca * I;
	zz = (x - y) * (x + y) + (2.0L * x * y) * I;

	zz = 1.0L - creall(zz) - cimagl(zz) * I;
	z2 = csqrtl(zz);

	zz = ct + z2;
	zz = clogl(zz);

	return zz * (-1.0L * I);
}
