#include "__complex.h"

static float _ctansf(float complex z)
{
	float f, x, x2, y, y2, rn, t, d;

	x = fabsf(2.0f * crealf(z));
	y = fabsf(2.0f * cimagf(z));
	x = redupif(x);
	x = x * x;
	y = y * y;

	x2 = 1.0f;
	y2 = 1.0f;
	f = 1.0f;
	rn = 0.0f;
	d = 0.0f;

	do {
		rn += 1.0f;
		f *= rn;
		rn += 1.0f;
		f *= rn;
		x2 *= x;
		y2 *= y;
		t = y2 + x2;
		t /= f;
		d += t;

		rn += 1.0f;
		f *= rn;
		rn += 1.0f;
		f *= rn;
		x2 *= x;
		y2 *= y;
		t = y2 - x2;
		t /= f;
		d += t;
	} while (fabsf(t / d) > MACHEPF);

	return d;
}

float complex ctanf(float complex z)
{
	float f = cosf(2.0f * crealf(z)) + coshf(2.0f * cimagf(z));

	if (fabsf(f) < 0.25f)
		f = _ctansf(z);

	if (f == 0.0f) {
		return HUGE_VALF + HUGE_VALF * I;
	}

	return sinf(2.0f * crealf(z)) / f + (sinhf(2.0f * cimagf(z)) / f) * I;
}
