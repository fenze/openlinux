#include <complex.h> // for cargl, complex
#include <math.h>    // for atan2l

long double cargl(long double complex z)
{
	return atan2l(__imag__ z, __real__ z);
}
