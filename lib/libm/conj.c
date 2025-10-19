#include "__complex.h"

double complex conj(double complex z)
{
	double_complex w = { .z = z };
	IMAG_PART(w) = -IMAG_PART(w);
	return (w.z);
}
