#include "__complex.h" // for redupif

#include <complex.h> // for complex, I, catanf, cimagf, crealf
#include <float.h>   // for FLT_MAX
#include <math.h>    // for atan2f, logf

float complex catanf(float complex z)
{
	float complex w;
	float a, t, x, x2, y;

	x = crealf(z);
	y = cimagf(z);

	if ((x == 0.0f) && (y > 1.0f))
		goto overflow;

	x2 = x * x;
	a = 1.0f - x2 - (y * y);
	if (a == 0.0f)
		goto overflow;

	t = 0.5f * atan2f(2.0f * x, a);
	w = redupif(t);

	t = y - 1.0f;
	a = x2 + (t * t);
	if (a == 0.0f)
		goto overflow;

	t = y + 1.0f;
	a = (x2 + (t * t)) / a;

	return w + (0.25f * logf(a)) * I;

overflow:
	return FLT_MAX + FLT_MAX * I;
}
