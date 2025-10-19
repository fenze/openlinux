#include "__complex.h"

long double complex csinl(long double complex z)
{
	long double ch, sh;
	cchshl(cimagl(z), &ch, &sh);
	return sinl(creall(z)) * ch +
	       (cosl(creall(z)) * sh) * (long double complex)I;
}
