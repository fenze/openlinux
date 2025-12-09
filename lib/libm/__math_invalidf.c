#include "libm.h" // for __math_invalidf

float __math_invalidf(float x)
{
	return (x - x) / (x - x);
}
