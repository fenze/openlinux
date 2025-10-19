#include "__complex.h"

long double creall(long double complex z)
{
	long_double_complex w = { .z = z };
	return (REAL_PART(w));
}
