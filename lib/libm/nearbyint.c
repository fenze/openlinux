

#include "bits/fenv.h" // for FE_INEXACT

#include <fenv.h> // for feclearexcept, fetestexcept
#include <math.h> // for nearbyint, rint

/* nearbyint is the same as rint, but it must not raise the inexact exception */

double nearbyint(double x)
{
#ifdef FE_INEXACT
#pragma STDC FENV_ACCESS ON
	int e;

	e = fetestexcept(FE_INEXACT);
#endif
	x = rint(x);
#ifdef FE_INEXACT
	if (!e)
		feclearexcept(FE_INEXACT);
#endif
	return x;
}
