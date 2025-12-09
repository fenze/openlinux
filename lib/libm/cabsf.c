#include <complex.h> // for cabsf, cimagf, crealf, complex
#include <math.h>    // for hypotf

float cabsf(float complex z)
{
	return hypotf(crealf(z), cimagf(z));
}
