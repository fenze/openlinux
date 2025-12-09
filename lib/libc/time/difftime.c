#include <time.h> // for time_t, difftime

double difftime(time_t time1, time_t time0)
{
	return (double)(time1 - time0);
}
