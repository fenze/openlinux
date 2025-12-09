#include "__complex.h" // for redupil

#include <complex.h> // for complex, I, catanl, cimagl, creall
#include <float.h>   // for LDBL_MAX
#include <math.h>    // for atan2l, logl

long double complex catanl(long double complex z)
{
	long double complex w;
	long double a, t, x, x2, y;

	x = creall(z);
	y = cimagl(z);

	if ((x == 0.0L) && (y > 1.0L))
		goto overflow;

	x2 = x * x;
	a = 1.0L - x2 - (y * y);
	if (a == 0.0)
		goto overflow;

	t = 0.5L * atan2l(2.0L * x, a);
	w = redupil(t);

	t = y - 1.0L;
	a = x2 + (t * t);
	if (a == 0.0L)
		goto overflow;

	t = y + 1.0L;
	a = (x2 + (t * t)) / a;
	return w + (0.25L * logl(a)) * I;

overflow:
	return LDBL_MAX + LDBL_MAX * I;
}
