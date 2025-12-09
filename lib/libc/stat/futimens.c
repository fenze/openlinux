#include <time.h> // for timespec

#define __BITS_STAT_H_
#include <bits/stat.h> // for timespec
#include <sys/stat.h>  // for utimensat, futimens

int futimens(int fd, const struct timespec times[2])
{
	return utimensat(fd, "", times, 0);
}
