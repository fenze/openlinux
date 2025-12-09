#include <math.h> // for lrintf, rintf

/* uses LONG_MAX > 2^24, see comments in lrint.c */

long lrintf(float x)
{
	return rintf(x);
}
