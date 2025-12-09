#ifndef __SYS_TIMES_H
#define __SYS_TIMES_H

#include <time.h>
typedef __INT64_TYPE__ clock_t;

struct tms {
	clock_t tms_utime;
	clock_t tms_stime;
	clock_t tms_cutime;
	clock_t tms_cstime;
};

clock_t times(struct tms *);

#endif
