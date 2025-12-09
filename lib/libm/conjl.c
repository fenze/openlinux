#include "__complex.h" // for IMAG_PART, long_double_complex

#include <complex.h> // for complex, conjl

long double complex conjl(long double complex z)
{
	long_double_complex w = { .z = z };
	IMAG_PART(w) = -IMAG_PART(w);
	return (w.z);
}
