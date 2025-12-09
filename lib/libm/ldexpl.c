#include <math.h> // for ldexpl, scalbnl

long double ldexpl(long double x, int n)
{
	return scalbnl(x, n);
}
