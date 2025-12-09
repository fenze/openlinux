#ifndef __SYS_SELECT_H
#define __SYS_SELECT_H

#define __BITS_SELECT_H_
#include <bits/select.h>

#define __BITS_TIMESPEC_H_
#include <bits/timespec.h>

struct timespec;
struct timeval;

typedef __UINT64_TYPE__ sigset_t;

int pselect(int, fd_set *restrict, fd_set *restrict, fd_set *restrict,
	    const struct timespec *restrict, const sigset_t *restrict);
int select(int, fd_set *restrict, fd_set *restrict, fd_set *restrict,
	   struct timeval *restrict);

#endif
