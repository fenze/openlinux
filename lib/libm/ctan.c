#include "__complex.h" // for redupi, MACHEP

#include <complex.h> // for cimag, creal, complex, I, ctan
#include <math.h>    // for fabs, HUGE_VAL, cos, cosh, sin, sinh

double _ctans(double complex z)
{
	double f, x, x2, y, y2, rn, t;
	double d;
	x = fabs(2.0 * creal(z));
	y = fabs(2.0 * cimag(z));
	x = redupi(x);
	x = x * x;
	y = y * y;
	x2 = 1.0;
	y2 = 1.0;
	f = 1.0;
	rn = 0.0;
	d = 0.0;
	do {
		rn += 1.0;
		f *= rn;
		rn += 1.0;
		f *= rn;
		x2 *= x;
		y2 *= y;
		t = y2 + x2;
		t /= f;
		d += t;
		rn += 1.0;
		f *= rn;
		rn += 1.0;
		f *= rn;
		x2 *= x;
		y2 *= y;
		t = y2 - x2;
		t /= f;
		d += t;
	} while (fabs(t / d) > MACHEP);
	return d;
}

double complex ctan(double complex z)
{
	double d = cos(2.0 * creal(z)) + cosh(2.0 * cimag(z));

	if (fabs(d) < 0.25)
		d = _ctans(z);

	if (d == 0.0) {
		return HUGE_VAL + HUGE_VAL * (double complex)I;
	}

	return sin(2.0 * creal(z)) / d +
	       (sinh(2.0 * cimag(z)) / d) * (double complex)I;
}
