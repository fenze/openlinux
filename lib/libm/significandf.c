#define _GNU_SOURCE
#include <math.h> // for ilogbf, scalbnf

float significandf(float x)
{
	return scalbnf(x, -ilogbf(x));
}
