#ifndef __SYS_RESOURCE_H
#define __SYS_RESOURCE_H

typedef __INT64_TYPE__ time_t;
typedef __INT64_TYPE__ suseconds_t;

struct __timeval {
	time_t tv_sec;
	suseconds_t tv_usec;
};

#define RUSAGE_SELF	0
#define RUSAGE_CHILDREN (-1)
#define RUSAGE_BOTH	(-2)
#define RUSAGE_THREAD	1

struct rusage {
	struct __timeval ru_utime;
	struct __timeval ru_stime;
	long ru_maxrss;
	long ru_ixrss;
	long ru_idrss;
	long ru_isrss;
	long ru_minflt;
	long ru_majflt;
	long ru_nswap;
	long ru_inblock;
	long ru_oublock;
	long ru_msgsnd;
	long ru_msgrcv;
	long ru_nsignals;
	long ru_nvcsw;
	long ru_nivcsw;
};

#define PRIO_MIN (-20)
#define PRIO_MAX 20

#define PRIO_PROCESS 0
#define PRIO_PGRP    1
#define PRIO_USER    2

int getpriority(int, int);
int setpriority(int, int, int);
int getrusage(int, struct rusage *);

#endif
