#include <time.h> // for localtime_r, localtime, time_t, tm

struct tm *localtime(const time_t *timer)
{
	static struct tm result;
	return localtime_r(timer, &result);
}
