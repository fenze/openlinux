#include <complex.h> // for complex, cimagl, creall, ctanhl, I
#include <math.h>    // for coshl, cosl, sinhl, sinl

long double complex ctanhl(long double complex z)
{
	long double x, y, d;

	x = creall(z);
	y = cimagl(z);
	d = coshl(2.0L * x) + cosl(2.0L * y);

	return sinhl(2.0L * x) / d + (sinl(2.0L * y) / d) * (long double complex)I;
}
