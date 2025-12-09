#include <complex.h> // for complex, I, cabsf, cargf, cimagf, cpowf, crealf
#include <math.h>    // for cosf, expf, logf, powf, sinf

float complex cpowf(float complex a, float complex z)
{
	float x, y, r, theta, absa, arga;
	x = crealf(z);
	y = cimagf(z);
	absa = cabsf(a);
	if (absa == 0.0f) {
		return (0.0f + 0.0f * I);
	}
	arga = cargf(a);
	r = powf(absa, x);
	theta = x * arga;
	if (y != 0.0f) {
		r = r * expf(-y * arga);
		theta = theta + y * logf(absa);
	}
	return r * cosf(theta) + (r * sinf(theta)) * I;
}
