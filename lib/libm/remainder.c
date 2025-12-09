#include "libm.h" // for weak_alias

#include <math.h> // for remainder, remquo

double remainder(double x, double y)
{
	int q;
	return remquo(x, y, &q);
}

weak_alias(remainder, drem);
