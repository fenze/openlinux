#include "__complex.h"

float complex cprojf(float complex z)
{
	float_complex w = { .z = z };

	if (isinf(crealf(z)) || isinf(cimagf(z))) {
		REAL_PART(w) = INFINITY;
		IMAG_PART(w) = copysignf(0.0, cimagf(z));
	}

	return w.z;
}
