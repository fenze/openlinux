#include "__complex.h" // for IMAG_PART, float_complex

#include <complex.h> // for cimagf, complex

float cimagf(float complex z)
{
	float_complex w = { .z = z };
	return (IMAG_PART(w));
}
