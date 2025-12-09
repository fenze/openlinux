#include "libm.h" // for __math_divzero, fp_barrier

#include <stdint.h> // for uint32_t

double __math_divzero(uint32_t sign)
{
	return fp_barrier(sign ? -1.0 : 1.0) / 0.0;
}
