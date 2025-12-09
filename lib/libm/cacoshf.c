#include <complex.h>

float complex cacoshf(float complex z)
{
	float complex w;

	return clogf(z + csqrtf(z + 1) * csqrtf(z - 1));
}
