#include <math.h>
#include <complex.h>

long double complex cacosl(long double complex z)
{
	long double complex w = casinl(z);
	return (M_PI_2 - creall(w)) - cimagl(w) * I;
}
