#include <complex.h> // for complex, cacosl, casinl, cimagl, creall, I
#include <math.h>    // for M_PI_2

long double complex cacosl(long double complex z)
{
	long double complex w = casinl(z);
	return (M_PI_2 - creall(w)) - cimagl(w) * I;
}
