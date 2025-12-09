#include "__complex.h"

long double complex ctanl(long double complex z)
{
	long double d = cosl(2.0L * creall(z)) + coshl(2.0L * cimagl(z));

	if (fabsl(d) < 0.25L) {
		d = ctansl(z);
	}

	if (d == 0.0L) {
		return HUGE_VALL + HUGE_VALL * (long double complex)I;
	}

	return sinl(2.0L * creall(z)) / d +
	       (sinhl(2.0L * cimagl(z)) / d) * (long double complex)I;
}
