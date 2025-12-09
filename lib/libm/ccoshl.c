#include <complex.h> // for ccoshl, cimagl, complex, creall, I
#include <math.h>    // for coshl, cosl, sinhl, sinl

long double complex ccoshl(long double complex z)
{
	long double x, y;

	x = creall(z);
	y = cimagl(z);

	return coshl(x) * cosl(y) + (sinhl(x) * sinl(y)) * I;
}
