#include "__complex.h" // for IMAG_PART, long_double_complex

#include <complex.h> // for cimagl, complex

long double cimagl(long double complex z)
{
	long_double_complex w = { .z = z };
	return IMAG_PART(w);
}
