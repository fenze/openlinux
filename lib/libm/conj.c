#include "__complex.h" // for IMAG_PART, double_complex

#include <complex.h> // for complex, conj

double complex conj(double complex z)
{
	double_complex w = { .z = z };
	IMAG_PART(w) = -IMAG_PART(w);
	return (w.z);
}
