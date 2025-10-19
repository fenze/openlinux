#include "__complex.h"

float cimagf(float complex z)
{
	float_complex w = { .z = z };
	return (IMAG_PART(w));
}
