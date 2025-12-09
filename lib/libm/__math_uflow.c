#include "libm.h" // for __math_xflow, __math_uflow

#include <stdint.h> // for uint32_t

double __math_uflow(uint32_t sign)
{
	return __math_xflow(sign, 0x1p-767);
}
