#include <float.h> // for LDBL_MANT_DIG, LDBL_MAX_EXP
#include <math.h>  // for remainderl, remquol

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
long double remainderl(long double x, long double y)
{
	return remainder(x, y);
}
#else
long double remainderl(long double x, long double y)
{
	int q;
	return remquol(x, y, &q);
}
#endif
