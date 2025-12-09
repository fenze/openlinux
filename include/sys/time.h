#ifndef __SYS_TIME_H
#define __SYS_TIME_H

#define __BITS_SELECT_H_
#include <bits/select.h>

struct timezone;

int select(int, fd_set *restrict, fd_set *restrict, fd_set *restrict,
	   struct timeval *restrict);
int gettimeofday(struct timeval *, struct timezone *);
char *strtotimeval(const char *, struct timeval *);
int utimes(const char *, const struct timeval[2]);

#endif
