#include "__complex.h"

long double cimagl(long double complex z)
{
	long_double_complex w = { .z = z };
	return IMAG_PART(w);
}
