#ifndef __SYS_RESOURCE_H
#define __SYS_RESOURCE_H

#include <time.h>

#define RUSAGE_SELF	0
#define RUSAGE_CHILDREN (-1)
#define RUSAGE_BOTH	(-2)
#define RUSAGE_THREAD	1

#define PRIO_MIN (-20)
#define PRIO_MAX 20

#define PRIO_PROCESS 0
#define PRIO_PGRP    1
#define PRIO_USER    2

#define RLIMIT_CPU     0
#define RLIMIT_FSIZE   1
#define RLIMIT_DATA    2
#define RLIMIT_STACK   3
#define RLIMIT_CORE    4
#define RLIMIT_RSS     5
#define RLIMIT_NPROC   6
#define RLIMIT_NOFILE  7
#define RLIMIT_MEMLOCK 8
#define RLIMIT_AS      9

typedef __INT64_TYPE__ time_t;
typedef __INT64_TYPE__ suseconds_t;
typedef __UINT64_TYPE__ rlim_t;

struct __timeval {
	time_t tv_sec;
	suseconds_t tv_usec;
};

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

struct rlimit {
	rlim_t rlim_cur;
	rlim_t rlim_max;
};

int getpriority(int, int);
int getrlimit(int, struct rlimit *);
int setrlimit(int, const struct rlimit *);
int setpriority(int, int, int);
int getrusage(int, struct rusage *);

#endif
