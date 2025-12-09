#include "__complex.h" // for cchshf

#include <complex.h> // for crealf, cimagf, complex, csinf, I
#include <math.h>    // for cosf, sinf

float complex csinf(float complex z)
{
	float ch, sh;
	cchshf(cimagf(z), &ch, &sh);
	return sinf(crealf(z)) * ch + (cosf(crealf(z)) * sh) * I;
}
