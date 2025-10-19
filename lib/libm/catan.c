#include <float.h>
#include "__complex.h"

double complex catan(double complex z)
{
	double complex w;
	double a, t, x, x2, y;

	x = creal(z);
	y = cimag(z);

	if ((x == 0.0) && (y > 1.0))
		goto overflow;

	x2 = x * x;
	a = 1.0 - x2 - (y * y);
	if (a == 0.0)
		goto overflow;

	t = 0.5 * atan2(2.0 * x, a);
	w = redupi(t);

	t = y - 1.0;
	a = x2 + (t * t);
	if (a == 0.0)
		goto overflow;

	t = y + 1.0;
	a = (x2 + (t * t)) / a;

	return w + (0.25 * log(a)) * I;

overflow:
	return DBL_MAX + DBL_MAX * I;
}
