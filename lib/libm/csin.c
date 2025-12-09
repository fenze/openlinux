#include "__complex.h" // for cchsh

#include <complex.h> // for creal, complex, cimag, csin, I
#include <math.h>    // for cos, sin

double complex csin(double complex z)
{
	double ch, sh;
	cchsh(cimag(z), &ch, &sh);
	return sin(creal(z)) * ch + (cos(creal(z)) * sh) * (double complex)I;
}
