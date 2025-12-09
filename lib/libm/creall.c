#include "__complex.h" // for REAL_PART, long_double_complex

#include <complex.h> // for creall, complex

long double creall(long double complex z)
{
	long_double_complex w = { .z = z };
	return (REAL_PART(w));
}
