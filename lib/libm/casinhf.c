#include <complex.h> // for I, casinf, casinhf, complex

float complex casinhf(float complex z)
{
	return -1.0f * I * casinf(z * I);
}
