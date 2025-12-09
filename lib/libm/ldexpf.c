#include <math.h> // for ldexpf, scalbnf

float ldexpf(float x, int n)
{
	return scalbnf(x, n);
}
