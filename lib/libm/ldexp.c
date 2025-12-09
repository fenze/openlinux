#include <math.h> // for ldexp, scalbn

double ldexp(double x, int n)
{
	return scalbn(x, n);
}
