#include <complex.h>

float complex casinf(float complex z)
{
	float complex ca, ct, zz, z2;
	float x, y;

	x = crealf(z);
	y = cimagf(z);
	ca = x + y * I;
	ct = ca * I;
	zz = (x - y) * (x + y) + (2.0f * x * y) * I;

	zz = 1.0f - crealf(zz) - cimagf(zz) * I;
	z2 = csqrtf(zz);

	zz = ct + z2;
	zz = clogf(zz);

	return zz * (-1.0f * I);
}
