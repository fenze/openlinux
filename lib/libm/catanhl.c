#include <complex.h>

long double complex catanhl(long double complex z)
{
	return -I * catanl(z * I);
}
