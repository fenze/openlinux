#include <complex.h> // for cexpl, cimagl, complex, creall, I
#include <math.h>    // for cosl, expl, sinl

long double complex cexpl(long double complex z)
{
	long double r, x, y;

	x = creall(z);
	y = cimagl(z);
	r = expl(x);

	return r * cosl(y) + r * sinl(y) * I;
}
