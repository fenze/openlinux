#include <stdlib.h> // for lldiv_t, lldiv

lldiv_t lldiv(long long numer, long long denom)
{
	lldiv_t result;
	result.quot = numer / denom;
	result.rem = numer % denom;
	return result;
}
