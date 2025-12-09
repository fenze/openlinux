#include <time.h> // for gmtime_r, time_t, localtime_r, timezone

struct tm *localtime_r(const time_t *restrict timer, struct tm *restrict result)
{
	time_t local = *timer - timezone;
	return gmtime_r(&local, result);
}
