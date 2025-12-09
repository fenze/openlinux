#include <math.h>   // for copysignf
#include <stdint.h> // for uint32_t

float copysignf(float x, float y)
{
	union {
		float f;
		uint32_t i;
	} ux = { x }, uy = { y };
	ux.i &= 0x7fffffff;
	ux.i |= uy.i & 0x80000000;
	return ux.f;
}
