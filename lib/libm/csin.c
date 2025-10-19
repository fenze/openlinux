#include "__complex.h"

double complex csin(double complex z)
{
	double ch, sh;
	cchsh(cimag(z), &ch, &sh);
	return sin(creal(z)) * ch + (cos(creal(z)) * sh) * (double complex)I;
}
