#include "__complex.h"

long double complex cprojl(long double complex z)
{
	long_double_complex w = { .z = z };

	if (isinf(creall(z)) || isinf(cimagl(z))) {
		REAL_PART(w) = (long double)INFINITY;
		IMAG_PART(w) = copysignl(0.0L, cimagl(z));
	}

	return (w.z);
}
