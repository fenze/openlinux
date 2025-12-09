#include <math.h> // for nextafterl, nexttowardl

long double nexttowardl(long double x, long double y)
{
	return nextafterl(x, y);
}
