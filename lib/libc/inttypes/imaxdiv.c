#include "stdint.h" // for intmax_t

#include <inttypes.h> // for imaxdiv_t, imaxdiv

imaxdiv_t imaxdiv(intmax_t num, intmax_t den)
{
	return (imaxdiv_t){ num / den, num % den };
}
