#include "libm.h" // for eval_as_float, __math_xflowf, fp_barrierf

#include <stdint.h> // for uint32_t

float __math_xflowf(uint32_t sign, float y)
{
	return eval_as_float(fp_barrierf(sign ? -y : y) * y);
}
