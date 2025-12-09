#include "__complex.h" // for cchshl

#include <complex.h> // for creall, ccosl, cimagl, complex, I
#include <math.h>    // for cosl, sinl

long double complex ccosl(long double complex z)
{
	long double ch, sh;
	cchshl(cimagl(z), &ch, &sh);
	return cosl(creall(z)) * ch - (sinl(creall(z)) * sh) * I;
}
