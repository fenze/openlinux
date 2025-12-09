#include "libm.h" // for __lgammaf_r, __signgam

#include <math.h> // for lgammaf

float lgammaf(float x)
{
	return __lgammaf_r(x, &__signgam);
}
