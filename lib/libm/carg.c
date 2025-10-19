#include <math.h>
#include <complex.h>

double carg(double complex z)
{
	return atan2(__imag__ z, __real__ z);
}
