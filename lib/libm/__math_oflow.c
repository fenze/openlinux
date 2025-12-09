#include "libm.h" // for __math_xflow, __math_oflow

#include <stdint.h> // for uint32_t

double __math_oflow(uint32_t sign)
{
	return __math_xflow(sign, 0x1p769);
}
