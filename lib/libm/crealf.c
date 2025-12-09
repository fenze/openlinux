#include "__complex.h" // for REAL_PART, float_complex

#include <complex.h> // for crealf, complex

float crealf(float complex z)
{
	float_complex w = { .z = z };
	return (REAL_PART(w));
}
