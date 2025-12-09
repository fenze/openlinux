#include "__complex.h" // for IMAG_PART, float_complex

#include <complex.h> // for complex, conjf

float complex conjf(float complex z)
{
	float_complex w = { .z = z };
	IMAG_PART(w) = -IMAG_PART(w);
	return (w.z);
}
