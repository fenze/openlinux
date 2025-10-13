#ifndef __TIME_H
#define __TIME_H

typedef __INT64_TYPE__ time_t;
typedef __INT32_TYPE__ clockid_t;

extern int daylight;
extern long timezone;
extern char *tzname[];

struct timespec {
	time_t tv_sec;
	long tv_nsec;
};

int nanosleep(const struct timespec *, struct timespec *);

#endif
