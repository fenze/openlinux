#include "__complex.h" // for IMAG_PART, REAL_PART, long_double_complex

#include <complex.h> // for cimagl, complex, cprojl, creall
#include <math.h>    // for copysignl, isinf, INFINITY

long double complex cprojl(long double complex z)
{
	long_double_complex w = { .z = z };

	if (isinf(creall(z)) || isinf(cimagl(z))) {
		REAL_PART(w) = (long double)INFINITY;
		IMAG_PART(w) = copysignl(0.0L, cimagl(z));
	}

	return (w.z);
}
