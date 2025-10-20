#include <time.h>

char *ctime(const time_t *clock)
{
	return asctime(localtime(clock));
}
