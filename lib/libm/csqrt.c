#include "__complex.h"

double complex csqrt(double complex z)
{
	double complex w;
	double x, y, r, t, scale;

	x = creal(z);
	y = cimag(z);
	if (y == 0.0) {
		if (x == 0.0) {
			return 0.0 + y * (double complex)I;
		} else {
			r = fabs(x);
			r = sqrt(r);
			if (x < 0.0) {
				return 0.0 + r * (double complex)I;
			} else {
				return r + y * (double complex)I;
			}
		}
	}

	if (x == 0.0) {
		r = fabs(y);
		r = sqrt(0.5 * r);

		if (y > 0)
			return r + r * (double complex)I;
		else
			return r - r * (double complex)I;
	}

	if ((fabs(x) > 4.0) || (fabs(y) > 4.0)) {
		x *= 0.25;
		y *= 0.25;
		scale = 2.0;
	} else {
		x *= 1.8014398509481984e16; /* 2^54 */
		y *= 1.8014398509481984e16;
		scale = 7.450580596923828125e-9; /* 2^-27 */
	}

	w = x + y * (double complex)I;
	r = cabs(w);
	if (x > 0) {
		t = sqrt(0.5 * r + 0.5 * x);
		r = scale * fabs((0.5 * y) / t);
		t *= scale;
	} else {
		r = sqrt(0.5 * r - 0.5 * x);
		t = scale * fabs((0.5 * y) / r);
		r *= scale;
	}

	if (y < 0)
		return t - r * (double complex)I;
	else
		return t + r * (double complex)I;
}
