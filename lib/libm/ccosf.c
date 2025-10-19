#include <complex.h>
#include "__complex.h"

double complex ccos(double complex z)
{
	double complex w;
	double ch, sh;

	cchsh(cimag(z), &ch, &sh);
	return cos(creal(z)) * ch - (sin(creal(z)) * sh) * I;
}
