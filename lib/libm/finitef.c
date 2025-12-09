#define _GNU_SOURCE
#include <math.h> // for isfinite

int finitef(float x)
{
	return isfinite(x);
}
