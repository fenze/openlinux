#include <complex.h> // for I, casinhl, casinl, complex

long double complex casinhl(long double complex z)
{
	return -1.0L * I * casinl(z * I);
}
