#include <math.h> // for ilogbf, logbf, isfinite

float logbf(float x)
{
	if (!isfinite(x))
		return x * x;
	if (x == 0)
		return -1 / (x * x);
	return ilogbf(x);
}
