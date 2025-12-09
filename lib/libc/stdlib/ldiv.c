#include <stdlib.h> // for ldiv_t, ldiv

ldiv_t ldiv(long numer, long denom)
{
	ldiv_t result;
	result.quot = numer / denom;
	result.rem = numer % denom;
	return result;
}
