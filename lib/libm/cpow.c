#include <complex.h> // for complex, I, cabs, carg, cimag, cpow, creal
#include <math.h>    // for cos, exp, log, pow, sin

double complex cpow(double complex a, double complex z)
{
	double x, y, r, theta, absa, arga;
	x = creal(z);
	y = cimag(z);
	absa = cabs(a);
	if (absa == 0.0) {
		return (0.0 + 0.0 * (double complex)I);
	}
	arga = carg(a);
	r = pow(absa, x);
	theta = x * arga;
	if (y != 0.0) {
		r = r * exp(-y * arga);
		theta = theta + y * log(absa);
	}
	return r * cos(theta) + (r * sin(theta)) * (double complex)I;
}
