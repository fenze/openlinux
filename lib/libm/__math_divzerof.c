#include "libm.h" // for __math_divzerof, fp_barrierf

#include <stdint.h> // for uint32_t

float __math_divzerof(uint32_t sign)
{
	return fp_barrierf(sign ? -1.0f : 1.0f) / 0.0f;
}
