#include "__complex.h"

float complex csinhf(float complex z)
{
	float x, y;

	x = crealf(z);
	y = cimagf(z);

	return sinhf(x) * cosf(y) + (coshf(x) * sinf(y)) * I;
}
