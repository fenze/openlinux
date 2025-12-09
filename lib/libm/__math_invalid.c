#include "libm.h" // for __math_invalid

double __math_invalid(double x)
{
	return (x - x) / (x - x);
}
