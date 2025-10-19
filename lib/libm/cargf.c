#include <math.h>
#include <complex.h>

float cargf(float complex z)
{
	return atan2f(__imag__ z, __real__ z);
}
