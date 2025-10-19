#include "__complex.h"

double complex cproj(double complex z)
{
	double_complex w = { .z = z };
	if (isinf(creal(z)) || isinf(cimag(z))) {
		REAL_PART(w) = (double)INFINITY;
		IMAG_PART(w) = copysign(0.0, cimag(z));
	}
	return (w.z);
}
