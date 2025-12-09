#include <complex.h> // for cargf, complex
#include <math.h>    // for atan2f

float cargf(float complex z)
{
	return atan2f(__imag__ z, __real__ z);
}
