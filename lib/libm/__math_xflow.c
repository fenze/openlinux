#include "libm.h" // for eval_as_double, __math_xflow, fp_barrier

#include <stdint.h> // for uint32_t

double __math_xflow(uint32_t sign, double y)
{
	return eval_as_double(fp_barrier(sign ? -y : y) * y);
}
