#include <math.h>   // for fabsf
#include <stdint.h> // for uint32_t

float fabsf(float x)
{
	union {
		float f;
		uint32_t i;
	} u = { x };
	u.i &= 0x7fffffff;
	return u.f;
}
