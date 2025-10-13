#ifndef __SYS_TIME_H
#define __SYS_TIME_H

typedef __INT64_TYPE__ time_t;
typedef __INT64_TYPE__ suseconds_t;

struct timeval {
	time_t tv_sec;
	suseconds_t tv_usec;
};

#endif
