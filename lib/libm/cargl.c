#include <math.h>
#include <complex.h>

long double cargl(long double complex z)
{
	return atan2l(__imag__ z, __real__ z);
}
