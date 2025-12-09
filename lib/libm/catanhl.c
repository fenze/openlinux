#include <complex.h> // for I, catanhl, catanl, complex

long double complex catanhl(long double complex z)
{
	return -I * catanl(z * I);
}
