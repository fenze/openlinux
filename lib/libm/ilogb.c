#include "libm.h" // for FORCE_EVAL

#include <limits.h> // for INT_MAX
#include <math.h>   // for ilogb, FP_ILOGB0, FP_ILOGBNAN
#include <stdint.h> // for uint64_t

int ilogb(double x)
{
#pragma STDC FENV_ACCESS ON
	union {
		double f;
		uint64_t i;
	} u = { x };
	uint64_t i = u.i;
	int e = i >> 52 & 0x7ff;

	if (!e) {
		i <<= 12;
		if (i == 0) {
			FORCE_EVAL(0 / 0.0f);
			return FP_ILOGB0;
		}
		/* subnormal x */
		for (e = -0x3ff; i >> 63 == 0; e--, i <<= 1)
			;
		return e;
	}
	if (e == 0x7ff) {
		FORCE_EVAL(0 / 0.0f);
		return i << 12 ? FP_ILOGBNAN : INT_MAX;
	}
	return e - 0x3ff;
}
