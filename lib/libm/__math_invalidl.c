#include "libm.h" // for __math_invalidl

#include <float.h> // for DBL_MANT_DIG, LDBL_MANT_DIG

#if LDBL_MANT_DIG != DBL_MANT_DIG
long double __math_invalidl(long double x)
{
	return (x - x) / (x - x);
}
#endif
