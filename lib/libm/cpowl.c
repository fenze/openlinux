#include "__complex.h"

long double complex cpowl(long double complex a, long double complex z)
{
	long double x, y, r, theta, absa, arga;
	x = creall(z);
	y = cimagl(z);
	absa = cabsl(a);
	if (absa == 0.0L) {
		return (0.0L + 0.0L * (long double complex)I);
	}
	arga = cargl(a);
	r = powl(absa, x);
	theta = x * arga;
	if (y != 0.0L) {
		r = r * expl(-y * arga);
		theta = theta + y * logl(absa);
	}
	return r * cosl(theta) + (r * sinl(theta)) * (long double complex)I;
}
