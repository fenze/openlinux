#include "__complex.h"

long double complex ccosl(long double complex z)
{
	long double ch, sh;
	cchshl(cimagl(z), &ch, &sh);
	return cosl(creall(z)) * ch - (sinl(creall(z)) * sh) * I;
}
