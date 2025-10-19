#include "__complex.h"

long double complex csinhl(long double complex z)
{
	long double x, y;

	x = creall(z);
	y = cimagl(z);

	return sinhl(x) * cosl(y) +
	       (coshl(x) * sinl(y)) * (long double complex)I;
}
