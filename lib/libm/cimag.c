#include "__complex.h" // for IMAG_PART, double_complex

#include <complex.h> // for cimag, complex

double cimag(double complex z)
{
	double_complex w = { .z = z };
	return (IMAG_PART(w));
}
