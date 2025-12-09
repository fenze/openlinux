#include "__complex.h"

float crealf(float complex z)
{
	float_complex w = { .z = z };
	return (REAL_PART(w));
}
