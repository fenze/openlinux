#include <complex.h> // for I, casin, casinh, complex

double complex casinh(double complex z)
{
	return -1.0 * I * casin(z * I);
}
