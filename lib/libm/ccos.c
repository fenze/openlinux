#include "__complex.h" // for cchsh

#include <complex.h> // for creal, ccos, cimag, complex, I
#include <math.h>    // for cos, sin

double complex ccos(double complex z)
{
	double ch, sh;

	cchsh(cimag(z), &ch, &sh);

	return cos(creal(z)) * ch - (sin(creal(z)) * sh) * I;
}
