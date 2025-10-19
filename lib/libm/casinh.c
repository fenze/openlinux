#include <complex.h>

double complex casinh(double complex z)
{
	return -1.0 * I * casin(z * I);
}
