#include <complex.h> // for complex, cacos, casin, cimag, creal, I
#include <math.h>    // for M_PI_2

double complex cacos(double complex z)
{
	double complex w = casin(z);
	return (M_PI_2 - creal(w)) - cimag(w) * I;
}
