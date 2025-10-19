#include <math.h>
#include <complex.h>

long double complex ccoshl(long double complex z)
{
	long double x, y;

	x = creall(z);
	y = cimagl(z);

	return coshl(x) * cosl(y) + (sinhl(x) * sinl(y)) * I;
}
