#include "__complex.h"

double creal(double complex z)
{
	double_complex w = { .z = z };
	return (REAL_PART(w));
}
