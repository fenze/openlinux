#include "__complex.h" // for IMAG_PART, REAL_PART, double_complex

#include <complex.h> // for cimag, complex, cproj, creal
#include <math.h>    // for copysign, isinf, INFINITY

double complex cproj(double complex z)
{
	double_complex w = { .z = z };
	if (isinf(creal(z)) || isinf(cimag(z))) {
		REAL_PART(w) = (double)INFINITY;
		IMAG_PART(w) = copysign(0.0, cimag(z));
	}
	return (w.z);
}
