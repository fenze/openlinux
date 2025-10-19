#include <complex.h>
#include "__complex.h"

double cimag(double complex z)
{
	double_complex w = { .z = z };
	return (IMAG_PART(w));
}
