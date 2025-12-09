#include "__complex.h" // for REAL_PART, double_complex

#include <complex.h> // for creal, complex

double creal(double complex z)
{
	double_complex w = { .z = z };
	return (REAL_PART(w));
}
