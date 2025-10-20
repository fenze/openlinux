#include <time.h>
#include <stdio.h>

char *asctime(const struct tm *timeptr)
{
	static char wday_name[7][3] = { "Sun", "Mon", "Tue", "Wed",
					"Thu", "Fri", "Sat" };
	static char mon_name[12][3] = { "Jan", "Feb", "Mar", "Apr",
					"May", "Jun", "Jul", "Aug",
					"Sep", "Oct", "Nov", "Dec" };
	static char result[26];

	snprintf(result, sizeof(result), "%.3s %.3s%3d %.2d:%.2d:%.2d %d\n",
		 wday_name[timeptr->tm_wday], mon_name[timeptr->tm_mon],
		 timeptr->tm_mday, timeptr->tm_hour, timeptr->tm_min,
		 timeptr->tm_sec, 1900 + timeptr->tm_year);

	return result;
}
