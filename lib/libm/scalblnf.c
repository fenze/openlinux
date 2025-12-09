#include <limits.h> // for INT_MAX, INT_MIN
#include <math.h>   // for scalblnf, scalbnf

float scalblnf(float x, long n)
{
	if (n > INT_MAX)
		n = INT_MAX;
	else if (n < INT_MIN)
		n = INT_MIN;
	return scalbnf(x, n);
}
