#include <complex.h>

float complex casinhf(float complex z)
{
	return -1.0f * I * casinf(z * I);
}
