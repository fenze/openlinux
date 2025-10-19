#include <math.h>
#include <complex.h>

double complex cacos(double complex z)
{
	double complex w = casin(z);
	return (M_PI_2 - creal(w)) - cimag(w) * I;
}
