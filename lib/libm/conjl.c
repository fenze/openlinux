#include "__complex.h"

long double complex conjl(long double complex z)
{
	long_double_complex w = { .z = z };
	IMAG_PART(w) = -IMAG_PART(w);
	return (w.z);
}
