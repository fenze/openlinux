

#include <float.h> // for LDBL_MANT_DIG, LDBL_MAX_EXP
#include <math.h>  // for nearbyintl, rintl

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
long double nearbyintl(long double x)
{
	return nearbyint(x);
}
#else
#include <fenv.h> // for feclearexcept, fetestexcept

long double nearbyintl(long double x)
{
#ifdef FE_INEXACT
#pragma STDC FENV_ACCESS ON
	int e;

	e = fetestexcept(FE_INEXACT);
#endif
	x = rintl(x);
#ifdef FE_INEXACT
	if (!e)
		feclearexcept(FE_INEXACT);
#endif
	return x;
}
#endif
