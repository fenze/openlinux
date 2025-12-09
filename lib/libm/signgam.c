#include "libm.h" // for __signgam, weak_alias

#include <math.h> // for signgam

int __signgam = 0;

weak_alias(__signgam, signgam);
