#include "__complex.h"

float complex conjf(float complex z)
{
	float_complex w = { .z = z };
	IMAG_PART(w) = -IMAG_PART(w);
	return (w.z);
}
