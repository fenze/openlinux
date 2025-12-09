#include "libm.h" // for FORCE_EVAL

#include <limits.h> // for INT_MAX
#include <math.h>   // for ilogbf, FP_ILOGB0, FP_ILOGBNAN
#include <stdint.h> // for uint32_t

int ilogbf(float x)
{
#pragma STDC FENV_ACCESS ON
	union {
		float f;
		uint32_t i;
	} u = { x };
	uint32_t i = u.i;
	int e = i >> 23 & 0xff;

	if (!e) {
		i <<= 9;
		if (i == 0) {
			FORCE_EVAL(0 / 0.0f);
			return FP_ILOGB0;
		}
		/* subnormal x */
		for (e = -0x7f; i >> 31 == 0; e--, i <<= 1)
			;
		return e;
	}
	if (e == 0xff) {
		FORCE_EVAL(0 / 0.0f);
		return i << 9 ? FP_ILOGBNAN : INT_MAX;
	}
	return e - 0x7f;
}
