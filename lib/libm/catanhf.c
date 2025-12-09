#include <complex.h>

float complex catanhf(float complex z)
{
	return -I * catanf(z * I);
}
