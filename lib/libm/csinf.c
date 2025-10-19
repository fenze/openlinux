#include "__complex.h"

float complex csinf(float complex z)
{
	float ch, sh;
	cchshf(cimagf(z), &ch, &sh);
	return sinf(crealf(z)) * ch + (cosf(crealf(z)) * sh) * I;
}
