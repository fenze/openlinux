#include <complex.h> // for I, catanf, catanhf, complex

float complex catanhf(float complex z)
{
	return -I * catanf(z * I);
}
