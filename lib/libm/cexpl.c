#include <math.h>
#include <complex.h>

long double complex cexpl(long double complex z)
{
	long double r, x, y;

	x = creall(z);
	y = cimagl(z);
	r = expl(x);

	return r * cosl(y) + r * sinl(y) * I;
}
