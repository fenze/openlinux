#include <complex.h>

long double complex cacoshl(long double complex z)
{
	return clogl(z + csqrtl(z + 1) * csqrtl(z - 1));
}
