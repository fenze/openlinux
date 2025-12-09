#include <complex.h> // for I, catan, catanh, complex

double complex catanh(double complex z)
{
	return -1.0 * I * catan(z * I);
}
