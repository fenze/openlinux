#include <math.h> // for tgamma, tgammaf

float tgammaf(float x)
{
	return (float)tgamma((double)x);
}
