#include <fenv.h>

int __fesetround(int);

int fesetround(int round)
{
	return __fesetround(round);
}
