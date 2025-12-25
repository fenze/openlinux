#include "__complex.h" // for cchshl

#include <complex.h> // for creall, complex, cimagl, csinl, I
#include <math.h>    // for cosl, sinl

long double complex csinl(long double complex z)
{
	long double ch, sh;
	cchshl(cimagl(z), &ch, &sh);
	return sinl(creall(z)) * ch + (cosl(creall(z)) * sh) * (long double complex)I;
}
