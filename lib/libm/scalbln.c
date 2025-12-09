#include <limits.h> // for INT_MAX, INT_MIN
#include <math.h>   // for scalbln, scalbn

double scalbln(double x, long n)
{
	if (n > INT_MAX)
		n = INT_MAX;
	else if (n < INT_MIN)
		n = INT_MIN;
	return scalbn(x, n);
}
