#include <time.h> // for asctime, localtime, ctime, time_t

char *ctime(const time_t *clock)
{
	return asctime(localtime(clock));
}
