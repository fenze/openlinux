#include "libm.h" // for __math_xflowf, __math_uflowf

#include <stdint.h> // for uint32_t

float __math_uflowf(uint32_t sign)
{
	return __math_xflowf(sign, 0x1p-95f);
}
