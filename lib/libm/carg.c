#include <complex.h> // for carg, complex
#include <math.h>    // for atan2

double carg(double complex z)
{
	return atan2(__imag__ z, __real__ z);
}
