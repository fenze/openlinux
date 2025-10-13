#ifndef __SELECT_H
#define __SELECT_H

#include <time.h>

typedef __INT64_TYPE__ time_t;
typedef __INT32_TYPE__ sigset_t;
typedef __INT64_TYPE__ suseconds_t;

#define FD_SETSIZE 1024

#define FD_ZERO(__s)                                                  \
	do {                                                          \
		int __i;                                              \
		unsigned long *__b = (__s)->fds_bits;                 \
		for (__i = sizeof(fd_set) / sizeof(long); __i; __i--) \
			*__b++ = 0;                                   \
	} while (0)
#define FD_SET(__d, __s)                                \
	((__s)->fds_bits[(__d) / (8 * sizeof(long))] |= \
	 (1UL << ((__d) % (8 * sizeof(long)))))
#define FD_CLR(__d, __s)                                \
	((__s)->fds_bits[(__d) / (8 * sizeof(long))] &= \
	 ~(1UL << ((__d) % (8 * sizeof(long)))))
#define FD_ISSET(__d, __s)                               \
	!!((__s)->fds_bits[(__d) / (8 * sizeof(long))] & \
	   (1UL << ((__d) % (8 * sizeof(long)))))

typedef struct {
	unsigned long fds_bits[16];
} fd_set;

struct timeval {
	time_t tv_sec;
	suseconds_t tv_usec;
};

int pselect(int, fd_set *restrict, fd_set *restrict, fd_set *restrict,
	    const struct timespec *restrict, const sigset_t *restrict);
int select(int, fd_set *restrict, fd_set *restrict, fd_set *restrict,
	   struct timeval *restrict);

#endif
