#include "libm.h" // for weak_alias

#include <math.h> // for remainderf, remquof

float remainderf(float x, float y)
{
	int q;
	return remquof(x, y, &q);
}

weak_alias(remainderf, dremf);
